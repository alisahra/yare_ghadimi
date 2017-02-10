#ifndef PUASEPAGE_H
#define PUASEPAGE_H

#include <QDialog>

namespace Ui {
class PuasePage;
}

class PuasePage : public QDialog
{
    Q_OBJECT

public:
    explicit PuasePage(QWidget *parent = 0);
    ~PuasePage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::PuasePage *ui;
};

#endif // PUASEPAGE_H
