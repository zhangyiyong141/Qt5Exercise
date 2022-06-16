#include "myrect.h"
#include "bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

MyRect::MyRect()
{
    setPixmap(QPixmap(":/images/picture/J20_n.png"));
    setTransformOriginPoint(50, 50);
}

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
}
