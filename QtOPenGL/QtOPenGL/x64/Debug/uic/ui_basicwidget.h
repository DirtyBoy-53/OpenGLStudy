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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "glrectangle.h"
#include "gltexture.h"
#include "gltextureunit.h"
#include "gltransform.h"
#include "gltriangle.h"

QT_BEGIN_NAMESPACE

class Ui_BasicWidgetClass
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *pageTriangle;
    QGridLayout *gridLayout;
    GLRectangle *openGLWidget_2;
    GLTriangle *openGLWidget_1;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    GLTexture *openGLWidget_3;
    GLTextureUnit *openGLWidget_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    GLTransform *openGLWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QOpenGLWidget *openGLWidget_5;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QOpenGLWidget *openGLWidget_6;

    void setupUi(QWidget *BasicWidgetClass)
    {
        if (BasicWidgetClass->objectName().isEmpty())
            BasicWidgetClass->setObjectName(QString::fromUtf8("BasicWidgetClass"));
        BasicWidgetClass->resize(646, 544);
        horizontalLayout = new QHBoxLayout(BasicWidgetClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(BasicWidgetClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        pageTriangle = new QWidget();
        pageTriangle->setObjectName(QString::fromUtf8("pageTriangle"));
        gridLayout = new QGridLayout(pageTriangle);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget_2 = new GLRectangle(pageTriangle);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));

        gridLayout->addWidget(openGLWidget_2, 0, 1, 1, 1);

        openGLWidget_1 = new GLTriangle(pageTriangle);
        openGLWidget_1->setObjectName(QString::fromUtf8("openGLWidget_1"));

        gridLayout->addWidget(openGLWidget_1, 0, 0, 1, 1);

        tabWidget->addTab(pageTriangle, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        openGLWidget_3 = new GLTexture(tab_3);
        openGLWidget_3->setObjectName(QString::fromUtf8("openGLWidget_3"));

        gridLayout_2->addWidget(openGLWidget_3, 0, 0, 1, 1);

        openGLWidget_4 = new GLTextureUnit(tab_3);
        openGLWidget_4->setObjectName(QString::fromUtf8("openGLWidget_4"));

        gridLayout_2->addWidget(openGLWidget_4, 0, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        openGLWidget = new GLTransform(tab_2);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout_3->addWidget(openGLWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        openGLWidget_5 = new QOpenGLWidget(tab);
        openGLWidget_5->setObjectName(QString::fromUtf8("openGLWidget_5"));

        gridLayout_4->addWidget(openGLWidget_5, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        openGLWidget_6 = new QOpenGLWidget(tab_4);
        openGLWidget_6->setObjectName(QString::fromUtf8("openGLWidget_6"));

        gridLayout_5->addWidget(openGLWidget_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(BasicWidgetClass);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(BasicWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *BasicWidgetClass)
    {
        BasicWidgetClass->setWindowTitle(QCoreApplication::translate("BasicWidgetClass", "BasicWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pageTriangle), QCoreApplication::translate("BasicWidgetClass", "\345\237\272\346\234\254\345\275\242\347\212\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("BasicWidgetClass", "\347\272\271\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("BasicWidgetClass", "\346\227\213\350\275\254\345\271\263\347\247\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("BasicWidgetClass", "\345\235\220\346\240\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("BasicWidgetClass", "\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasicWidgetClass: public Ui_BasicWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICWIDGET_H
