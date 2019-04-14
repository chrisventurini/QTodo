#include "MainWindow.h"
#include <QtWidgets/QApplication>

#include <DomainEventDispatcher.h>

using QTodo::Domain::DomainEventDispatcher;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	DomainEventDispatcher dispatcher;
	QTodo::MainWindow w(dispatcher);

	w.show();
	return a.exec();
}
