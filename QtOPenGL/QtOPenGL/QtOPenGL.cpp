#include "QtOPenGL.h"

QtOPenGL::QtOPenGL(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.tabWidget->setCurrentIndex(0);
}

QtOPenGL::~QtOPenGL()
{}
