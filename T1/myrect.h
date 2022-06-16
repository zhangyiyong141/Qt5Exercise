#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>

class MyRect : public QGraphicsPixmapItem
{
    //玩家角色，尺寸100x100
public:
    MyRect();
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYRECT_H
