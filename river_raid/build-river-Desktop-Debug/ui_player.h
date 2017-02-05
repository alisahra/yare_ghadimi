/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_player
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *player)
    {
        if (player->objectName().isEmpty())
            player->setObjectName(QString::fromUtf8("player"));
        player->resize(400, 300);
        menuBar = new QMenuBar(player);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        player->setMenuBar(menuBar);
        mainToolBar = new QToolBar(player);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        player->addToolBar(mainToolBar);
        centralWidget = new QWidget(player);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        player->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(player);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        player->setStatusBar(statusBar);

        retranslateUi(player);

        QMetaObject::connectSlotsByName(player);
    } // setupUi

    void retranslateUi(QMainWindow *player)
    {
        player->setWindowTitle(QApplication::translate("player", "player", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class player: public Ui_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
