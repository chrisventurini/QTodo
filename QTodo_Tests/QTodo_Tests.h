#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTodo_Tests.h"

class QTodo_Tests : public QMainWindow
{
	Q_OBJECT

public:
	QTodo_Tests(QWidget *parent = Q_NULLPTR);

private:
	Ui::QTodo_TestsClass ui;
};
