#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    //敌机大小，尺寸100x100
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};


#endif // ENEMY_H
