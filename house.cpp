#include <QTimer>
#include "house.h"

House::House(QWidget *p):
    QWidget(p)
{
    resize(800,800);

    sun = new Sun(this, 1.8, 350);
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
    outDoorLight = false;
    inDoorLight = false;
    timer = new QTimer(this->parent());
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOutDeal()));

}

void House::paintEvent(QPaintEvent *)
{

}

// deal with status
void House::deal()
{

    inDoorLight = sunAngle >0.6 && sunAngle <3.0 ;
    outDoorLight = sunAngle >0.6 && sunAngle <3.0 ;

}

void House::timeOutDeal()
{
    sunAngle  += 0.5;
    if(sunAngle >6.28)
        sunAngle = 0;
    sun->adjustAngle(sunAngle);
    deal();
}
