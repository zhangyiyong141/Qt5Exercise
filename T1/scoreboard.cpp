#include "scoreboard.h"
#include <QFont>

ScoreBoard::ScoreBoard(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the score to 0
    _score = 0;

    setPlainText(QString("Score:") + QString::number(_score));
    setDefaultTextColor(Qt::GlobalColor::blue);
    setFont(QFont("times", 16));
}

int ScoreBoard::getScore() const
{
    return _score;
}

void ScoreBoard::increase()
{
    _score++;
    setPlainText(QString("Score:") + QString::number(_score));
}
