#include "myrect.h"
#include "bullet.h"
#include <QDebug>
#include <QGraphicsScene>

MyRect::MyRect()
{
    setPixmap(QPixmap(":/images/picture/20_n.png"));
    setTransformOriginPoint(50, 50);

}

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;

    //解决左右移动按键冲突
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
    {
        if (keys[Qt::Key_Left] == false && keys[Qt::Key_Right]  == false)
        {
            _holdingRow = 0;
        }
    }
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
    {
        if (keys[Qt::Key_Up] == false && keys[Qt::Key_Down]  == false)
        {
            _holdingColumn = 0;
        }
    }

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;

    //解决左右移动按键冲突
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
    {
        _holdingRow++;
        keys[event->key()] = _holdingRow;
    }
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
    {
        _holdingColumn++;
        keys[event->key()] = _holdingColumn;
    }
}

void MyRect::keyboardControlCallback()
{
    QString txt = "myrect pressed:";

    if(keys[Qt::Key_Up])
    {
        txt += "up";
        if (keys[Qt::Key_Up] > keys[Qt::Key_Down])
        {
            if (pos().y() > 0)
            {
                setPos(x(), y()-10);
            }
        }
    }
    if(keys[Qt::Key_Down])
    {
        txt += "down";
        if (keys[Qt::Key_Down] > keys[Qt::Key_Up])
        {
            if (pos().y() + 100 < 600)
            {
                setPos(x(), y()+10);
            }
        }
    }
    if(keys[Qt::Key_Left])
    {
        txt += "left";
        if (keys[Qt::Key_Left] > keys[Qt::Key_Right])
        {
            if (pos().x() > 0)
            {
                setPos(x()-10, y());
            }
        }
    }
    if(keys[Qt::Key_Right])
    {
        txt += "right";
        if (keys[Qt::Key_Right] > keys[Qt::Key_Left])
        {
            if (pos().x() + 100 < 800)
            {
                setPos(x()+10, y());
            }
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
