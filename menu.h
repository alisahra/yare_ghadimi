#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "setting.h"
namespace Ui {
class MenU;
}

class MenU : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenU(QWidget *parent = 0);
    ~MenU();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MenU *ui;
    Setting * setting;
};

#endif // MENU_H
