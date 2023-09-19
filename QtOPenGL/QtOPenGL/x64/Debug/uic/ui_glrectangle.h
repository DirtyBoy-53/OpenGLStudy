/********************************************************************************
** Form generated from reading UI file 'glrectangle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLRECTANGLE_H
#define UI_GLRECTANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLRectangleClass
{
public:

    void setupUi(QWidget *GLRectangleClass)
    {
        if (GLRectangleClass->objectName().isEmpty())
            GLRectangleClass->setObjectName(QString::fromUtf8("GLRectangleClass"));
        GLRectangleClass->resize(600, 400);

        retranslateUi(GLRectangleClass);

        QMetaObject::connectSlotsByName(GLRectangleClass);
    } // setupUi

    void retranslateUi(QWidget *GLRectangleClass)
    {
        GLRectangleClass->setWindowTitle(QCoreApplication::translate("GLRectangleClass", "GLRectangle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLRectangleClass: public Ui_GLRectangleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLRECTANGLE_H
