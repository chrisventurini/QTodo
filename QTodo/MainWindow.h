#pragma once

#include <QtWidgets/QMainWindow>
#include <DomainEventDispatcher.h>
#include "ui_MainWindow.h"

namespace QTodo
{

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent, Domain::DomainEventDispatcher& dispatcher);
	MainWindow(Domain::DomainEventDispatcher& dispatcher);

private:
	void onNewTodoCreatePushButtonClicked() const;

	Ui::MainWindowClass ui;
	Domain::DomainEventDispatcher& dispatcher_;
};

}

