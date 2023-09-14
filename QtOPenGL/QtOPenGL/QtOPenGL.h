#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOPenGL.h"

class QtOPenGL : public QMainWindow
{
    Q_OBJECT

public:
    QtOPenGL(QWidget *parent = nullptr);
    ~QtOPenGL();

private:
    Ui::QtOPenGLClass ui;
};
