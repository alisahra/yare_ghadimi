#include "menu.h"
#include "ui_menu.h"
#include "game.h"
#include "setting.h"
#include "certain.h"

extern Game * game;

Setting * setting;
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    setting = new Setting();
    setting->setWindowTitle("CHOOSING LEVEL");
    setting->show();
}

void Menu::on_pushButton_3_clicked()
{
    Certain * certain = new Certain();
    certain->setWindowTitle("Warning!");
    certain->show();
}
