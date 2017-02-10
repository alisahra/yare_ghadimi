#include "menu.h"
#include "ui_menu.h"
#include "game.h"
#include "setting.h"
#include "certain.h"
#include "buy.h"

extern Game * game;

Setting * setting;
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    QPixmap bkgnd(":/pic/Picture/image.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
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


void Menu::on_pushButton_2_clicked()
{
    Buy * buy = new Buy();
    buy->setWindowTitle("Trial Time");
    buy->show();
}
