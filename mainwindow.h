#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
class Sender;
class Receiver;
class Room;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Generate();//TODO
    void ReceiveInstructions();//TODO
    void SendInfo();//TODO
    void initHouse();
    void dealHouse();

public slots:
    void timeOutDeal();

private slots:
    void on_actionSpeed_up_triggered();

    void on_actionSlow_down_triggered();

private:
    Ui::MainWindow *ui;
    Sender *sender;
    Receiver *receiver;
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
