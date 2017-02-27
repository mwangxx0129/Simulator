#include "door.h"


Door::Door(QWidget *par)
    :QWidget(par)
{

}

void Door::paintEvent(QPaintEvent *)
{
    static const QPoint leftDoor[4] = {
        QPoint(-60,-20),
        QPoint(-60,100),
        QPoint(0,100),
        QPoint(0,-20)
    };
    static const QPoint rightDoor[4] = {
        QPoint(0,-20),
        QPoint(0,100),
        QPoint(60,100),
        QPoint(60,-20)
    };
    static const QPoint front[4] = {
        QPoint(-80,100),
        QPoint(-100,140),
        QPoint(60,140),
        QPoint(80,100)
    };
    QPainter painter(this);
    resize(800,800);
    painter.scale(1, 1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.setPen(Qt::black);
    painter.setBrush(QColor(172,170,77));
    painter.save();
    painter.drawConvexPolygon(leftDoor,4);
    painter.drawConvexPolygon(rightDoor,4);

    painter.setBrush(QColor(118,108,52));
    painter.drawConvexPolygon(front,4);
    painter.restore();
    this->raise();

}
