#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController();
    GameController(QGraphicsScene * scene);

public slots:
    void spawn();

private:
    QGraphicsScene * _onlyScene = NULL;
};

#endif // GAMECONTROLLER_H
