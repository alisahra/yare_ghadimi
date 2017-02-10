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
    QFile levelF("level.txt");
    QTextStream in(&levelF);
    if(!levelF.open(QFile::ReadOnly)){
        qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
    }
    QString line = in.readLine();
    level = line.toInt();
    levelF.close();

    level++;

    QFile levelF1("level.txt");
    levelF1.open(QIODevice::WriteOnly);
    if(!levelF.open(QFile::WriteOnly)){
        qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
    }
    QTextStream out(&levelF1);
    out << level;
    levelF1.close();

    qDebug() << "Level increased " << level;

    if(level <= 20){
        speed->setSpeed(level);
    }
}

int Level::getSpeed() {
    return speed->getSpeed();
}

int Level::getLevel() {
    return level;
}
