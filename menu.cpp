#include "menu.h"
#include "ui_menu.h"

static bool state = true;
MenU::MenU(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenU)
{
    ui->setupUi(this);
}

MenU::~MenU()
{
    delete ui;
}

void MenU::on_pushButton_3_clicked()
{
    if(state)
        state = false;
        setting = new Setting(this);
        setting->setWindowTitle("SETTING");
        setting->show();
}
