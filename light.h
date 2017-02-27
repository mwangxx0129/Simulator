#ifndef LIGHT_H
#define LIGHT_H
#include <QWidget>
#include <QPainter>

class Light:public QWidget
{
public:
    Light(QWidget *par, bool i = false);
    void paintEvent(QPaintEvent *);
    void adjustColor(bool isO);
private:
    bool isOn;
};

#endif // LIGHT_H
