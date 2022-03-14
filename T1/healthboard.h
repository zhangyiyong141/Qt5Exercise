#ifndef HEALTHBOARD_H
#define HEALTHBOARD_H
#include <QGraphicsTextItem>

class HealthBoard : public QGraphicsTextItem
{
public:
    HealthBoard(QGraphicsItem * parent=0);

    int health() const;
    void decrease();

private:
    int _health = 0;
};

#endif // HEALTHBOARD_H
