/********************************************************************************
** Form generated from reading UI file 'fly_bird.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLY_BIRD_H
#define UI_FLY_BIRD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fly_bird
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fly_bird)
    {
        if (fly_bird->objectName().isEmpty())
            fly_bird->setObjectName("fly_bird");
        fly_bird->resize(800, 600);
        centralwidget = new QWidget(fly_bird);
        centralwidget->setObjectName("centralwidget");
        fly_bird->setCentralWidget(centralwidget);
        menubar = new QMenuBar(fly_bird);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        fly_bird->setMenuBar(menubar);
        statusbar = new QStatusBar(fly_bird);
        statusbar->setObjectName("statusbar");
        fly_bird->setStatusBar(statusbar);

        retranslateUi(fly_bird);

        QMetaObject::connectSlotsByName(fly_bird);
    } // setupUi

    void retranslateUi(QMainWindow *fly_bird)
    {
        fly_bird->setWindowTitle(QCoreApplication::translate("fly_bird", "fly_bird", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fly_bird: public Ui_fly_bird {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLY_BIRD_H
