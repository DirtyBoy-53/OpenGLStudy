/********************************************************************************
** Form generated from reading UI file 'basicwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICWIDGET_H
#define UI_BASICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasicWidgetClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_2;

    void setupUi(QWidget *BasicWidgetClass)
    {
        if (BasicWidgetClass->objectName().isEmpty())
            BasicWidgetClass->setObjectName(QString::fromUtf8("BasicWidgetClass"));
        BasicWidgetClass->resize(638, 516);
        horizontalLayout = new QHBoxLayout(BasicWidgetClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(BasicWidgetClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(BasicWidgetClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BasicWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *BasicWidgetClass)
    {
        BasicWidgetClass->setWindowTitle(QCoreApplication::translate("BasicWidgetClass", "BasicWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("BasicWidgetClass", "\345\237\272\346\234\254\345\275\242\347\212\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("BasicWidgetClass", "\347\272\271\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("BasicWidgetClass", "\346\227\213\350\275\254\345\271\263\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasicWidgetClass: public Ui_BasicWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICWIDGET_H
