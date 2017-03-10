#include <QtMath>
#include "sun.h"

Sun::Sun(QWidget *par, double a, int r)
    :QWidget(par), angleSun(a), radius(r)
{
    // Get the position of sun
    pos = QPoint(-radius * qCos(angleSun),
                 -radius * qSin(angleSun));
}

void Sun::paintEvent(QPaintEvent *)
{
    pos = QPoint(-radius * qCos(angleSun),
                 -radius * qSin(angleSun));
    QPainter painter(this);
    resize(800,800);
    painter.scale(1, 1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
//painter.setBrush(QColor(255,255,0));
    painter.setBrush(Qt::yellow);
    painter.save();
//    painter.drawEllipse(QPoint(-350* qCos(1.5), -350*qSin(1.5)), 20,20);
    if(pos.y()<0)
        painter.drawEllipse(QPoint(0,0), 30,30);
    painter.restore();
    this->move(pos);
}

void Sun::adjustAngle(double a)
{
    angleSun = a;
    repaint();
}
