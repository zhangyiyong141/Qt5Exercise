#include "myrect.h"
#include "bullet.h"
#include <QDebug>
#include <QGraphicsScene>

MyRect::MyRect()
{
    setPixmap(QPixmap(":/images/picture/J20_n.png"));
    setTransformOriginPoint(50, 50);

}
/*
void MyRect::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        {
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
        {
            setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);
        qDebug() << "fire a bullet.";
    }
}*/

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    //左按 右按 右松 左松
    //holding 左
    //右 左 右
    //holding 右
    keys[event->key()] = false;

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;
    if (event->key() == Qt::Key_Left)
    {
        if (!_holdingRight)
            _holdingLeft = true;
        keys[Qt::Key_Right] = false;
    }
    if (event->key() == Qt::Key_Right)
    {
        if (!_holdingLeft)
            _holdingRight = true;
        keys[Qt::Key_Left] = false;
    }
    if (event->key() == Qt::Key_Up)
    {
        keys[Qt::Key_Down] = false;
    }
    if (event->key() == Qt::Key_Down)
    {
        keys[Qt::Key_Up] = false;
    }
}

void MyRect::keyboardControlCallback()
{
    QString txt = "myrect pressed:";

    if(keys[Qt::Key_Up])
    {
        txt += "up";
        setPos(x(), y()-10);
    }
    if(keys[Qt::Key_Down])
    {
        txt += "down";
        setPos(x(), y()+10);
    }
    if(keys[Qt::Key_Left])
    {
        txt += "left";
        if (pos().x() > 0)
        {\
            setPos(x()-10, y());
        }
    }
    if(keys[Qt::Key_Right])
    {
        txt += "right";
        if (pos().x() + 100 < 800)
        {
            setPos(x()+10, y());
        }
    }
    if (keys[Qt::Key_Space])
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);
        qDebug() << "fire a bullet.";
    }

    qDebug() << txt;
}
