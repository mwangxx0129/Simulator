#include "light.h"

Light::Light(QWidget *par, bool i)
    :QWidget(par),isOn(i)
{}

void Light::paintEvent(QPaintEvent *)
{
    static const QPoint lightCover[3]={
        QPoint(74,-30),
        QPoint(64,-20),
        QPoint(82,-20)
    };
    static const QPoint lightArea[4] = {
        QPoint(-160,100),
        QPoint(-200,200),
        QPoint(100,200),
        QPoint(160,100)
    };
    QPainter painter(this);
    resize(800,800);
    painter.scale(1, 1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.save();

    painter.setBrush(QColor(118,108,52));
    painter.drawConvexPolygon(lightCover,3);
    painter.setPen(Qt::NoPen);
    if(isOn){
        painter.setBrush(Qt::green);
        painter.drawConvexPolygon(lightArea,4);
        painter.setBrush(Qt::yellow);
    }
    painter.drawEllipse(70,-20,8,8);
    painter.restore();
    this->raise();
}

void Light::adjustColor(bool isO)
{
    isOn = isO;
    repaint();
}
