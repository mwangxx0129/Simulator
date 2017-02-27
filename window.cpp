#include "window.h"

Window::Window(QWidget * par, QPoint p,
               QPoint lt, QPoint lb,
               QPoint rb, QPoint rt,
               bool is, bool isB, bool isL)
    :QWidget(par), position(p),
      isDay(is), isBlind(isB),isLight(isL)
{
    fourPoint[0] = lt;
    fourPoint[1] = lb;
    fourPoint[2] = rb;
    fourPoint[3] = rt;
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    resize(800,800);
    painter.scale(1, 1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.setPen(QColor((124,252,0)));

    if(isLight)
        painter.setBrush(Qt::yellow);
    else if(isBlind && isDay)
        painter.setBrush(Qt::white);
    else
        painter.setBrush(QColor(30,30,30));
    painter.save();
    painter.drawConvexPolygon(fourPoint,4);
    painter.restore();
    this->move(position);
    this->raise();
}

void Window::adjustColor(bool is)
{
    isDay = is;
    repaint();
}

void Window::adjustBlind(bool is)
{
    isBlind =is;
    repaint();
}

void Window::adjustLight(bool isO)
{
    isLight = isO;
    repaint();
}

