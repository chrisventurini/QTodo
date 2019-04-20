#include "MainWindow.h"

#include <string>
#include <utility>
#include <Todo.h>
#include <TodoCreatedEvent.h>
#include <DomainEventDispatcher.h>

using QTodo::Domain::DomainEventDispatcher;
using QTodo::Domain::Todo;
using QTodo::Domain::TodoCreatedEvent;
using std::string;

namespace QTodo
{
	MainWindow::MainWindow(QWidget *parent, Domain::DomainEventDispatcher& dispatcher)
		: QMainWindow(parent), dispatcher_(dispatcher)
	{
		ui.setupUi(this);

		const QPushButton* const newTodoCreatePushBtn = findChild<QPushButton*>("newTodoCreatePushButton");

		connect(newTodoCreatePushBtn, &QPushButton::clicked, this, &MainWindow::onNewTodoCreatePushButtonClicked);
	}

	MainWindow::MainWindow(Domain::DomainEventDispatcher& dispatcher) : MainWindow(Q_NULLPTR, dispatcher) {}

	void MainWindow::onNewTodoCreatePushButtonClicked() const 
	{
		auto const newTodoTitleLine = findChild<QLineEdit*>("newTodoTitleLineEdit");

		QString newTodoTile = newTodoTitleLine->text();

		const Todo newTodo(newTodoTile.toStdString());
		const TodoCreatedEvent todoCreatedEvent(newTodo);

		dispatcher_.Dispatch(todoCreatedEvent);

		newTodoTitleLine->setText("");
	}

}
