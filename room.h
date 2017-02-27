#ifndef ROOM_H
#define ROOM_H
#include <QWidget>
#include <QPainter>

class Room:public QWidget
{
public:
    Room(QWidget *, bool );
    void paintEvent(QPaintEvent *);
    void adjustColor(bool i);
private:
    bool isDay;
};

#endif // ROOM_H
