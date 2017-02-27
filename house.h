#ifndef HOUSE_H
#define HOUSE_H
#include <QWidget>
#include <QPainter>
#include "sun.h"
#include "grass.h"
#include "room.h"
#include "window.h"
#include "door.h"
#include "light.h"

class House:public QWidget
{
public:
    House(QWidget *p = 0);
    void paintEvent(QPaintEvent *);
    void deal();

public slots:
    void timeOutDeal();

private:
    Sun *sun;
    Grass *grass;
    Room *room;
    Window *windows[6];
    Door *door;
    Light *light;

    QTimer *timer;
    //status
    double sunAngle;
    bool outDoorLight;
    bool inDoorLight;

};

#endif // HOUSE_H
