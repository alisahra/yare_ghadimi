#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class myPlayer : public QObject , public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};


#endif // PLAYER_H
