#include <QtMath>
#include "grass.h"

Grass::Grass(QWidget *par, QPoint p,
             QPoint lt, QPoint lb,
             QPoint rb, QPoint rt, bool i)
    :QWidget(par), position(p), isDay(i)
{
    fourPoint[0] = lt;
    fourPoint[1] = lb;
    fourPoint[2] = rb;
    fourPoint[3] = rt;
}

void Grass::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    resize(800,800);
    painter.scale(1, 1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.save();
    painter.setPen(Qt::gray);
    isDay ? painter.setBrush(Qt::green):painter.setBrush(QColor(0,40,0));

    painter.drawConvexPolygon(fourPoint,4);
    painter.restore();
    this->move(position);
    this->raise(); // in front of Sun in night
}

void Grass::AdjustColor(bool is)
{
    isDay = is;
    repaint();
}
