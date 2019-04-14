#include <gtest/gtest.h>

#include <DomainEventDispatcher.h>
#include <MainWindow.h>

using QTodo::Domain::DomainEventDispatcher;
using QTodo::MainWindow;

TEST(MainWindow, WhenConstructing)
{
	DomainEventDispatcher dispatcher;

	MainWindow SUT(dispatcher);
}