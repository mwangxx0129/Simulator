#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include "house.h"

#include "sender.h"
#include "receiver.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Simulator");

    initHouse();
    timer = new QTimer(this);
    timerInterval = 1000;
    timer->start(timerInterval); // update time
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOutDeal()));

    // init server
    server = new QTcpServer();
    server->listen(QHostAddress::Any,6663); // (IP, port) will be changed
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    // init server
}

MainWindow::~MainWindow()
{
    delete ui;
}

//!------DO NOT REVISE BELOW---------------------------------------------------|
void MainWindow::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void MainWindow::readClient()
{
    QString messages = clientConnection->readAll();
    DealInstructions(messages);
}

//!------DO NOT REVISE ABOVE---------------------------------------------------|

void MainWindow::DealInstructions(QString messages)
{
    // deal json
    QByteArray content;
    content.append(messages);
    QJsonDocument itemDoc = QJsonDocument::fromJson(content);
    QJsonObject rootObject = itemDoc.object();

    if(rootObject.isEmpty())
        return;
    instrOutLight = rootObject.value("instrOutLight").toBool();
    instrInLight =  rootObject.value("instrInLight").toBool();
    instrBlind = rootObject.value("instrBlind").toBool();
    isBlind = instrBlind;

    for(int i = 0; i<6; i++){
        windows[i]->adjustBlind(instrBlind);
        windows[i]->adjustLight(instrInLight);
    }


    light->adjustColor(instrOutLight);

}

void MainWindow::SendInfo()
{
    // Generate JSON
    QJsonObject bodyJson{
        {"isDay", isDay},
        {"enableOutDoorLight",enableOutDoorLight},
        {"enableInDoorLight", enableInDoorLight},
        {"isOutLight",isOutLight},
        {"isInLight",isInLight},
        {"isBlind",isBlind}
    };
    QJsonDocument doc(bodyJson);
    QString strJson(doc.toJson(QJsonDocument::Indented));

    // Create TCP sender
    QTcpSocket * client;
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("134.154.68.218"), 6667); // Send to (IP, PORT)
    QByteArray message;
    message.append(strJson);
    client->write(message);
}

void MainWindow::initHouse()
{
    resize(800,800);

    sun = new Sun(this, 0, 350);
    grass = new Grass(this, QPoint(0,0),
                      QPoint(-380,0),QPoint(-380,200),
                      QPoint(380,200),QPoint(380,0),true);
    //tree = new Tree(this);
    room = new Room(this,true);

    windows[0] = new Window(this,QPoint(-180,-180),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(80,100),QPoint(80,0));
    windows[1] = new Window(this,QPoint(100,-180),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(80,100),QPoint(80,0));
    windows[2] = new Window(this,QPoint(-180,-20),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(80,100),QPoint(80,0));
    windows[3] = new Window(this,QPoint(100,-20),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(80,100),QPoint(80,0));
    windows[4] = new Window(this, QPoint(220,-180),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(60,70),QPoint(60,-20));
    windows[5] = new Window(this, QPoint(220,-20),
                            QPoint(0,0),QPoint(0,100),
                            QPoint(60,70),QPoint(60,-20));
    door = new Door(this);
    light = new Light(this,false);

    // init status
    sunAngle = 0;
    enableOutDoorLight = true;
    enableInDoorLight = true;
    isOutLight = false;
    isInLight = false;
    isBlind = false;
}

void MainWindow::dealHouse()
{
    sunAngle  += 0.005;
    if(sunAngle >6.28)
        sunAngle = 0;
    sun->adjustAngle(sunAngle);
    isDay = sunAngle < 3.14;
    grass->AdjustColor(isDay);
    room->adjustColor(isDay);
    light->adjustColor(!isDay && enableOutDoorLight);
    for(int i = 0; i< 6; i++){
        windows[i]->adjustColor(isDay);
        windows[i]->adjustLight(!isDay && enableInDoorLight);
    }

}

void MainWindow::timeOutDeal()
{
    //1. Generate simulator info
    dealHouse();

    //2. Send info to Sever
    SendInfo();

    //3. Receive info from Sever
//    ReceiveInstructions();

    //4. Deal instructions
}


