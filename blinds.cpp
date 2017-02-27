#include <QWidget>
#include <QtMath>
#include "blinds.h"

Blinds::Blinds(QWidget *par, int w, int h, double a)
    :QWidget(par), blindWidth(w), blindHeight(h), blindAngle(a)
{
    resize(400,300);
}

// Called by timer in real time
void Blinds::paintEvent(QPaintEvent *)
{
    int halfWidth = blindWidth/2;
    int halfHeight = blindHeight/2;
    static const QPoint blind[4] = {
        QPoint(-halfWidth + halfHeight *qSin(blindAngle), halfHeight * qCos(blindAngle)),
        QPoint(-halfWidth - halfHeight *qSin(blindAngle), -halfHeight * qCos(blindAngle)),
        QPoint(halfWidth - halfHeight *qSin(blindAngle), -halfHeight * qCos(blindAngle)),
        QPoint(halfWidth + halfHeight *qSin(blindAngle),halfHeight * qCos(blindAngle))
    };
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.save();
    painter.drawConvexPolygon(blind ,4);
    painter.restore();
}

// Pos: Adjust angle of blind and repaint
void Blinds::adjustAngle(double a)
{
    blindAngle = a;
    repaint();
}
