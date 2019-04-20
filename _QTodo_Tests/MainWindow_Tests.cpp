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

TEST(MainWindow, WhenCreatingANewTodo_ItShouldClearTheTitleLineEdit)
{
	DomainEventDispatcher dispatcher;
	MainWindow SUT(dispatcher);

	auto newTodoTitleLineEdit = SUT.findChild<QLineEdit*>("newTodoTitleLineEdit");

	newTodoTitleLineEdit->setText("title");

	// Action
	SUT.findChild<QPushButton *>("newTodoCreatePushButton")->click();

	ASSERT_EQ(newTodoTitleLineEdit->text(), "");
}

TEST(MainWindow, WhenCreatingANewTodo_ItShouldDispatchATodoCreatedEvent)
{
	DomainEventDispatcher dispatcher;
	MainWindow SUT(dispatcher);

	std::unique_ptr<DomainEvent<Todo>> dispatchedEvent = nullptr;

	dispatcher.Subscribe<Todo>(TodoCreatedEvent::EVENT_TYPE, [&](const DomainEvent<Todo>& todoCreatedEvent)
	{
		const Todo dispatchedTodo(todoCreatedEvent.GetPayload().get());

		dispatchedEvent = std::make_unique<TodoCreatedEvent>(dispatchedTodo);
	});

	SUT.findChild<QLineEdit*>("newTodoTitleLineEdit")->setText("title");

	// Action
	SUT.findChild<QPushButton *>("newTodoCreatePushButton")->click();

	// Expected Result
	const TodoCreatedEvent expectedEvent(Todo("title"));

	ASSERT_NE(dispatchedEvent, nullptr);
	ASSERT_EQ(*dispatchedEvent, expectedEvent);
}


