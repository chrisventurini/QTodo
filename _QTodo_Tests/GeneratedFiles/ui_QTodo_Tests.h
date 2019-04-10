/********************************************************************************
** Form generated from reading UI file 'QTodo_Tests.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTODO_TESTS_H
#define UI_QTODO_TESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTodo_TestsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTodo_TestsClass)
    {
        if (QTodo_TestsClass->objectName().isEmpty())
            QTodo_TestsClass->setObjectName(QString::fromUtf8("QTodo_TestsClass"));
        QTodo_TestsClass->resize(600, 400);
        menuBar = new QMenuBar(QTodo_TestsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QTodo_TestsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTodo_TestsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QTodo_TestsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTodo_TestsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QTodo_TestsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTodo_TestsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QTodo_TestsClass->setStatusBar(statusBar);

        retranslateUi(QTodo_TestsClass);

        QMetaObject::connectSlotsByName(QTodo_TestsClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTodo_TestsClass)
    {
        QTodo_TestsClass->setWindowTitle(QApplication::translate("QTodo_TestsClass", "QTodo_Tests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTodo_TestsClass: public Ui_QTodo_TestsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTODO_TESTS_H
