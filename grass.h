#ifndef GRASS_H
#define GRASS_H
#include <QWidget>
#include <QPainter>

class Grass:public QWidget
{
public:
    Grass(QWidget *par, QPoint, QPoint, QPoint, QPoint, QPoint, bool i = false);
    void paintEvent(QPaintEvent *);
    void AdjustColor(bool is);
private:
    QPoint position;
    QPoint fourPoint[4];
    bool isDay;
};

#endif // GRASS_H
