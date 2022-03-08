#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet()
{
    setRect(0,0,10,10);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //碰撞检测，消灭敌人
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i=0; i<colliding_items.size(); i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted.";
    }
}
