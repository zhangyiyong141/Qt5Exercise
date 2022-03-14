#include "healthboard.h"
#include <QFont>

HealthBoard::HealthBoard(QGraphicsItem * parent) : QGraphicsTextItem(parent)
{
    //initialize the health to 100
    _health = 100;

    setPlainText(QString("Health:") + QString::number(_health));
    setDefaultTextColor(Qt::GlobalColor::red);
    setFont(QFont("times", 16));
}

int HealthBoard::health() const
{
    return _health;
}

void HealthBoard::decrease()
{
    _health--;
    setPlainText(QString("Health:") + QString::number(_health));
}
