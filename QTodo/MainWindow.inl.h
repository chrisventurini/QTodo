#pragma once

namespace QTodo
{

template <typename Dispatcher>
MainWindow::MainWindow(QWidget *parent, Dispatcher& dispatcher)
	: QMainWindow(parent), dispatcher_(dispatcher)
{
	ui.setupUi(this);
}

}
