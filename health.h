#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem {
private:
    int health;
public:
    Health(QGraphicsItem * parent=0);
    void increase();
    int getHealth();
public slots:
    void decrease();
};


#endif // HEALTH_H
