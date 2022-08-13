#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

extern Game * game;//以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。

Bullet::Bullet()
{
    //setRect(0,0,10,10);
    setPixmap(QPixmap(":/images/picture/bullet.png"));
    setTransformOriginPoint(-4, 0);
    setScale(0.05);

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
            //得分
            game->getScoreBoard()->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-10);
    if (pos().y() + 10 < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted.";
    }
}
