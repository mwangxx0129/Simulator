#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>
#include <QPainter>

class Window:public QWidget
{
public:
    Window(QWidget *par, QPoint, QPoint, QPoint, QPoint, QPoint,
           bool is = false, bool isB = false, bool isL = false);
    void paintEvent(QPaintEvent *);
    void adjustColor(bool is);
    void adjustBlind(bool is);
    void adjustLight(bool isO);
private:
    QPoint position;
    QPoint fourPoint[4];
    bool isDay;
    bool isBlind;
    bool isLight;
};

#endif // WINDOW_H
