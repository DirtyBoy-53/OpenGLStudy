#pragma once
#include <QWidget>
#include "ui_basicwidget.h"

class BasicWidget : public QWidget
{
	Q_OBJECT

public:
	BasicWidget(QWidget *parent = nullptr);
	~BasicWidget();

private:
	Ui::BasicWidgetClass ui;
};
