#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QtWidgets>
#include <QMap>
#include <QTimer>

class MyRect : public QGraphicsPixmapItem
{
    //玩家角色，尺寸100x100
public:
    MyRect();
public:
    //void keyPressEvent(QKeyEvent * event);

    //----  ----键盘输入----  ----
    public:
        QMap<int, bool> keys;
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    public:
        void keyboardControlCallback();

private:
        bool _holdingLeft = false;
        bool _holdingRight = false;
        bool _holdingUp = false;
        bool _holdingDown = false;
    //----  ----键盘输入----  ----
};


#endif // MYRECT_H
