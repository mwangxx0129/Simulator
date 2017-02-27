#ifndef DOOR_H
#define DOOR_H
#include <QWidget>
#include <QPainter>

class Door:public QWidget
{
public:
    Door(QWidget *par);
    void paintEvent(QPaintEvent *);
private:
    QPoint fourPoint[4];
};

#endif // DOOR_H
