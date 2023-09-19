/********************************************************************************
** Form generated from reading UI file 'QtOPenGL.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTOPENGL_H
#define UI_QTOPENGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "basicwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtOPenGLClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    BasicWidget *pageBasic;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtOPenGLClass)
    {
        if (QtOPenGLClass->objectName().isEmpty())
            QtOPenGLClass->setObjectName(QString::fromUtf8("QtOPenGLClass"));
        QtOPenGLClass->resize(882, 555);
        centralWidget = new QWidget(QtOPenGLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        pageBasic = new BasicWidget();
        pageBasic->setObjectName(QString::fromUtf8("pageBasic"));
        tabWidget->addTab(pageBasic, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        QtOPenGLClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtOPenGLClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 882, 23));
        QtOPenGLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtOPenGLClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtOPenGLClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtOPenGLClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtOPenGLClass->setStatusBar(statusBar);

        retranslateUi(QtOPenGLClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QtOPenGLClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtOPenGLClass)
    {
        QtOPenGLClass->setWindowTitle(QCoreApplication::translate("QtOPenGLClass", "QtOPenGL", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pageBasic), QCoreApplication::translate("QtOPenGLClass", "\345\237\272\347\241\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QtOPenGLClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtOPenGLClass: public Ui_QtOPenGLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTOPENGL_H
