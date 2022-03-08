#include "gamecontroller.h"
#include "enemy.h"
#include <QGraphicsScene>

GameController::GameController()
{

}

GameController::GameController(QGraphicsScene *scene)
{
    _onlyScene = scene;
}

void GameController::spawn()
{
    //创建一个敌人在场景中
    Enemy * enemy = new Enemy();
    _onlyScene->addItem(enemy);
}
