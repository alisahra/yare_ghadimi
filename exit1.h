#ifndef EXIT1_H
#define EXIT1_H

#include <QDialog>

namespace Ui {
class Exit1;
}

class Exit1 : public QDialog
{
    Q_OBJECT

public:
    explicit Exit1(QWidget *parent = 0);
    ~Exit1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Exit1 *ui;
};

#endif // EXIT1_H
