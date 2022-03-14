#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsTextItem>

class ScoreBoard : public QGraphicsTextItem
{
public:
    ScoreBoard(QGraphicsItem * parent=0);

    int getScore() const;
    void increase();

private:
    int _score = 0;
};

#endif // SCOREBOARD_H
