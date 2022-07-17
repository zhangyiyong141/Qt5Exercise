#include "game.h"
#include <QBrush>
#include <QImage>
#include <QDebug>


Game::Game(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    //创建Qt可视化场景
     _scene = new QGraphicsScene();
     _view = new QGraphicsView(_scene);
     _view->setBackgroundBrush(QBrush(QImage(":/images/picture/bg.png")));

     //创建游戏场景中必要设置控制器
     _gameController = new GameController(_scene);

     //创建一个游戏主角色，由玩家控制
     _player = new MyRect();

     //游戏界面
     _scoreBoard = new ScoreBoard();
     _healthBoard = new HealthBoard();

}

void Game::show()
{
    //创建Qt可视化场景
    _scene->setSceneRect(0,0,800,600);  //背景尺寸800x600
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->show();
    _view->setFixedSize(810, 610);


    //创建一个游戏主角色，由玩家控制
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    //_player->setFocus();
    _player->setPos(_view->width()/2, _view->height() -150);
    _scene->addItem(_player);

    //游戏界面
    _scene->addItem(_scoreBoard);
    _healthBoard->setPos(_healthBoard->x(), _healthBoard->y() + 25);
    _scene->addItem(_healthBoard);

    //游戏主线程计时器
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), _gameController, SLOT(spawn()));
    timer->start(2000);

     QTimer * _keyboardEventTimer = new QTimer();
    _keyboardEventTimer->setInterval(1000/60);
    QObject::connect(_keyboardEventTimer, SIGNAL(timeout()), this, SLOT(keyboardControlCallback()));
     _keyboardEventTimer->start();
}

ScoreBoard *Game::getScoreBoard()
{
    return _scoreBoard;
}

HealthBoard *Game::getHealthBoard()
{
    return _healthBoard;
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
    QWidget::keyReleaseEvent(event);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        qDebug() << "event key left";
    }
    keys[event->key()] = true;
    QWidget::keyPressEvent(event);
    qDebug() << "event key exe";
}

void Game::keyboardControlCallback()
{
    _player->keyboardControlCallback();
}
