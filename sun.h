#ifndef SUN_H
#define SUN_H
#include <QWidget>
#include <QPainter>

class Sun:public QWidget
{
public:
    Sun(QWidget *par, double a, int r);
    void paintEvent(QPaintEvent *);
    void adjustAngle(double a);
private:
    double angleSun;
    int radius;
    QPoint pos;
};

#endif // SUN_H
