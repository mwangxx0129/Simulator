#include "coordinator.h"

Coordinator::Coordinator(QWidget *parent) : QWidget(parent)
{

}

void Coordinator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int w = width();
    int h = height();

    painter.setPen(Qt::black);
    painter.save();
    painter.drawPoint(40,10);
    painter.drawLine(0,0,800,0);
    painter.drawLine(0,0,0,800);
    painter.restore();
}
