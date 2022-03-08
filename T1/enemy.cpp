#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Enemy::Enemy()
{
    //设置随机初始位置
    int random_number = qrand() % 700;
    setPos(random_number, 0);

    //绘制敌人图标
    setRect(0,0,100,100);

    //好用简单的计时器，每多少秒执行操作
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    //敌人的移动方式，简单的向下移动
    setPos(x(), y()+5);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted.";
    }
}
