#include <gtest/gtest.h>

#include <DomainEventDispatcher.h>
#include <MainWindow.h>
#include <Todo.h>
#include <TodoCreatedEvent.h>

using QTodo::Domain::DomainEvent;
using QTodo::Domain::DomainEventDispatcher;
using QTodo::Domain::TodoCreatedEvent;
using QTodo::Domain::Todo;
using QTodo::MainWindow;

TEST(MainWindow, WhenCreatingANewTodo_ItShouldDispatchATodoCreatedEvent)
{
	DomainEventDispatcher dispatcher;
	MainWindow SUT(dispatcher);

	DomainEvent<Todo>* dispatchedEvent = nullptr;

	dispatcher.Subscribe<Todo>(TodoCreatedEvent::EVENT_TYPE, [&](DomainEvent<Todo>& todoCreatedEvent)
	{
		dispatchedEvent = &todoCreatedEvent;
	});

	SUT.findChild<QPushButton *>("newTodoCreatePushButton")->click();

	ASSERT_NE(dispatchedEvent, nullptr);
}