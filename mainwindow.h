#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtNetwork>
#include <QMainWindow>
#include "sun.h"
#include "grass.h"
#include "room.h"
#include "window.h"
#include "door.h"
#include "light.h"

namespace Ui {
class MainWindow;
}

class Room;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Generate();//TODO
    void DealInstructions(QString messages);
    void SendInfo();//TODO
    void initHouse();
    void dealHouse();

public slots:
    void timeOutDeal();

private slots:
    void acceptConnection();
    void readClient();

private:
    Ui::MainWindow *ui;

    //TCP
    QTcpServer *server;
    QTcpSocket *clientConnection;

    QTimer *timer;
    int timerInterval;


    Sun *sun;
    Grass *grass;
    Room *room;
    Window *windows[6];
    Door *door;
    Light *light;

    //status
    double sunAngle;
    bool isDay;
    bool enableOutDoorLight;
    bool enableInDoorLight;
    bool isOutLight;
    bool isInLight;
    bool isBlind;

    //instructions
    bool instrOutLight;
    bool instrInLight;
    bool instrBlind;
};

#endif // MAINWINDOW_H
