                /*IN THE NAME OF ALLAH*/
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenU w;
    w.setWindowTitle("RIVER RAID");
    w.show();
    return a.exec();
}
