#include <QTimer>
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
    sender = new Sender(45455); //45455 as sender port
    receiver = new Receiver(45453); //45453 as receiver port

    initHouse();

    timer = new QTimer(this);
    timerInterval = 100;
    timer->start(timerInterval); // update time
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOutDeal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveInstructions()
{
    //ui->label->setText(receiver->processPendingDatagrams().data());
}

void MainWindow::SendInfo()
{
    QString body = "is Sunday" +QString::number(isDay)
            +"out Door Light Open"+ QString::number(enableOutDoorLight);

    sender->broadcastDatagram(body);
}

void MainWindow::initHouse()
{
    resize(800,800);

    sun = new Sun(this, 0, 350);
    grass = new Grass(this, QPoint(0,0),
                      QPoint(-380,0),QPoint(-380,200),
                      QPoint(380,200),QPoint(380,0),true);
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
    //1. Generate
    dealHouse();//simulator info,

    //2. Send info to Sever
    SendInfo();

    //3. Receive info from Sever
    ReceiveInstructions();

    //4. Deal instructions
}


void MainWindow::on_actionSpeed_up_triggered()
{
    timerInterval -=10;
    if(timerInterval <=30)
        timerInterval = 30;
    timer->start(timerInterval);
}

void MainWindow::on_actionSlow_down_triggered()
{
    timerInterval +=10;
    if(timerInterval >=2000)
        timerInterval = 2000;
    timer->start(timerInterval);
}
