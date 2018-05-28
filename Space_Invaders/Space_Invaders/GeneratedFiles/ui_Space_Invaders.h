/********************************************************************************
** Form generated from reading UI file 'Space_Invaders.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPACE_INVADERS_H
#define UI_SPACE_INVADERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Space_InvadersClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Space_InvadersClass)
    {
        if (Space_InvadersClass->objectName().isEmpty())
            Space_InvadersClass->setObjectName(QStringLiteral("Space_InvadersClass"));
        Space_InvadersClass->resize(600, 400);
        menuBar = new QMenuBar(Space_InvadersClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Space_InvadersClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Space_InvadersClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Space_InvadersClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Space_InvadersClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Space_InvadersClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Space_InvadersClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Space_InvadersClass->setStatusBar(statusBar);

        retranslateUi(Space_InvadersClass);

        QMetaObject::connectSlotsByName(Space_InvadersClass);
    } // setupUi

    void retranslateUi(QMainWindow *Space_InvadersClass)
    {
        Space_InvadersClass->setWindowTitle(QApplication::translate("Space_InvadersClass", "Space_Invaders", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Space_InvadersClass: public Ui_Space_InvadersClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPACE_INVADERS_H
