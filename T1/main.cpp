#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    MyRect * rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    scene->addItem(rect);

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    return a.exec();
}
