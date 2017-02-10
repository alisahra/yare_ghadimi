#include "buy.h"
#include "ui_buy.h"
#include <QDesktopServices>
#include <QUrl>
Buy::Buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buy)
{
    ui->setupUi(this);
}

Buy::~Buy()
{
    delete ui;
}

void Buy::on_pushButton_2_clicked()
{
    this->close();
}

void Buy::on_pushButton_clicked()
{
    QString link = "https://www.credit-suisse.com/";
    QDesktopServices::openUrl(QUrl(link));
}
