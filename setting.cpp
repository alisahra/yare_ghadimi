#include "setting.h"
#include "ui_setting.h"
extern bool* pState;
Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_buttonBox_accepted()
{

}
