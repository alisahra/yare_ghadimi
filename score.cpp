#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem (parent) {
    // initialize score
    score = 0;

    // draw score
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
    setZValue(2000);
}

void Score::increase(int a) {
    score += a;

    // draw score
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() {
    return score;
}
