#ifndef GAME_H
#define GAME_H
#include "myrect.h"
#include "gamecontroller.h"
#include "scoreboard.h"
#include "healthboard.h"
#include <QGraphicsView>
#include <QGraphicsScene>


class Game
{
public:
    Game();
    void show();

    ScoreBoard* getScoreBoard();
    HealthBoard* getHealthBoard();

private:
    //创建Qt可视化场景
    QGraphicsScene * _scene = NULL;
    QGraphicsView * _view = NULL;

    //创建游戏场景中必要设置控制器
    GameController * _gameController = NULL;

    //创建一个游戏主角色，由玩家控制
    MyRect * _player = new MyRect();

    //游戏界面
    ScoreBoard * _scoreBoard = NULL;
    HealthBoard * _healthBoard = NULL;
};

#endif // GAME_H
