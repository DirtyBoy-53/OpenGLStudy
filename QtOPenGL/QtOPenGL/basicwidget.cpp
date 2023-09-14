#include "basicwidget.h"

BasicWidget::BasicWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tabWidget->setCurrentIndex(0);
}

BasicWidget::~BasicWidget()
{}
