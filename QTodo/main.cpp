#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTodo::MainWindow w;
	w.show();
	return a.exec();
}
