#ifndef CERTAIN_H
#define CERTAIN_H

#include <QDialog>

namespace Ui {
class Certain;
}

class Certain : public QDialog
{
    Q_OBJECT

public:
    explicit Certain(QWidget *parent = 0);
    ~Certain();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Certain *ui;
};

#endif // CERTAIN_H
