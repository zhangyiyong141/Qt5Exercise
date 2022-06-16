#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

extern Game * game;//以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。
Enemy::Enemy()
{
    //设置随机初始位置
    int random_number = qrand() % 700;


    //绘制敌人图标
    setPixmap(QPixmap(":/images/picture/japan_0_warii.png"));
    setTransformOriginPoint(50, 50);
    setRotation(180);
    setScale(0.25);

    //setRect(0,0,100,100);
    setPos(random_number, 0 - 100);

    //好用简单的计时器，每多少秒执行操作
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    //敌人的移动方式，简单的向下移动
    setPos(x(), y()+5);
    if (pos().y() > 600)
    {
        //扣分
        game->getHealthBoard()->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy demage.";
    }
}
