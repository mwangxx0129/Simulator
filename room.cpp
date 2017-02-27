#include <QtMath>
#include "window.h"

#include "room.h"


Room::Room(QWidget *par, bool is)
    :QWidget(par), isDay(is)
{
}

void Room::paintEvent(QPaintEvent *)
{
    resize(800,800);
    static const QPoint face[5] ={
        QPoint(-200,-200),
        QPoint(-200, 100),
        QPoint(200,100),
        QPoint(200,-200),
        QPoint(0,-300)
    };
    static const QPoint roof[4] = {
        QPoint(0,-300),
        QPoint(200, -200),
        QPoint(300,-230),
        QPoint(100,-330)
    };
    static const QPoint side[4] = {
        QPoint(300,-230),
        QPoint(200,-200),
        QPoint(200,100),
        QPoint(300,50)
    };
    int w = width();
    int h = height();
    QPainter painter(this);
    painter.scale(1, 1 );
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.setPen(Qt::gray);

    painter.setBrush(isDay?QColor(185,185,100):QColor(125,125,54));//200-0
    painter.save();
    // coordinator
    painter.drawLine(-w/2,0, w/2,0);
    painter.drawLine(0,-h/2,0,h/2);

    painter.drawConvexPolygon(face,5);
    painter.drawConvexPolygon(side,4);

    painter.setBrush(isDay ? QColor(100,100,50) : QColor(80,80,50));
    painter.drawConvexPolygon(roof,4);
    painter.restore();
    this->raise();

}

void Room::adjustColor(bool i)
{
    isDay = i;
    repaint();
}
