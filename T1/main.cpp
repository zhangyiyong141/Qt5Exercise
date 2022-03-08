#include "gamecontroller.h"
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建Qt可视化场景
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800, 600);

    //创建游戏场景中必要设置控制器
    GameController * gameController = new GameController(scene);

    //创建一个游戏主角色，由玩家控制
    MyRect * player = new MyRect();
    player->setRect(0, 0, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->setPos(view->width()/2, view->height() - player->rect().height());

    //游戏主线程计时器
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), gameController, SLOT(spawn()));
    timer->start(2000);
    return a.exec();
}
