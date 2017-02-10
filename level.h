#ifndef LEVEL_H
#define LEVEL_H

#include "speed.h"
#include <QObject>

class Level : public QObject{
    Q_OBJECT
public:
    Level(int a);
    void setLvl(int a);
    // getter
    int getSpeed();
    int getLevel();

public slots:
    void incLvl();
private:
    Speed * speed;
    int level;
};

#endif // LEVEL_H
