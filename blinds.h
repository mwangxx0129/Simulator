#ifndef BLINDS_H
#define BLINDS_H

#include <QWidget>
#include <QPainter>

class Blinds:public QWidget
{
private:
    int blindWidth;
    int blindHeight;
    double blindAngle;
public:
    Blinds(QWidget *,int, int, double);
    void paintEvent(QPaintEvent *);
    void adjustAngle(double a);
};

#endif // BLINDS_H
