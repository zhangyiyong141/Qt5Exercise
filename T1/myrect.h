#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QtWidgets>
#include <QMap>
#include <QTimer>

class MyRect : public QGraphicsPixmapItem
{
    //玩家可操作的玩家角色，尺寸100x100
public:
    MyRect();
public:
    //void keyPressEvent(QKeyEvent * event);

    //----  ----键盘输入----  ----
    public:
        QMap<int, int> keys;
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    public:
        void keyboardControlCallback();

private:
        //解决左右移动按键冲突
        int _holdingRow = 0;

        //解决上下移动按键冲突
        int _holdingColumn = 0;
    //----  ----键盘输入----  ----
};


#endif // MYRECT_H
