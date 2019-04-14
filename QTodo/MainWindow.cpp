#include "MainWindow.h"

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

void MainWindow::onNewTodoCreatePushButtonClicked()
{
	const QLineEdit* const newTodoTitleLine = findChild<QLineEdit*>("newTodoTitleLineEdit");

	QString newTodoTile = newTodoTitleLine->text();
}

}
