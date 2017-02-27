#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <QWidget>
#include <QPainter>
class Coordinator : public QWidget
{
public:
    explicit Coordinator(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

};

#endif // COORDINATOR_H
