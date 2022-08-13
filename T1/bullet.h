#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
//QGraphicsRectItem
class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
