#include "level.h"
#include <QDebug>
#include <QFile>

Level::Level(int a)
{
    level = a;
    qDebug() << level;
}

void Level::setLvl(int a){
    level = a;
    if(level <= 20){
        speed->setSpeed(level);
    }else if(level > 20){
        speed->setSpeed(20);
    }
}

void Level::incLvl()
{
    level++;
    QFile levelF("level.txt");
    if(!levelF.open(QFile::WriteOnly)){
        qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
    }
    QTextStream out(&levelF);
    out << level;
    levelF.close();

    qDebug() << "Level increased";
    if(level <= 20){
        speed->setSpeed(level);
    }
}

int Level::getSpeed(){
    return speed->getSpeed();
}

int Level::getLevel(){
    return level;
}
