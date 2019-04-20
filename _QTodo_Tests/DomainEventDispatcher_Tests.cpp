#include "gtest/gtest.h"

#include "QTodoDomain.h"

using QTodo::Domain::DomainEvent;
using QTodo::Domain::DomainEventDispatcher;
using QTodo::Domain::Todo;
using QTodo::Domain::TodoCreatedEvent;

TEST(DomainEventDispatcher, WhenSubscribing_WithAFunction_ShouldBeCalledWhenDispatched)
{
	DomainEventDispatcher SUT;

	bool called = false;

	SUT.Subscribe<Todo>(TodoCreatedEvent::EVENT_TYPE, [&](const DomainEvent<Todo>&)
	{
		called = true;
	});

	const Todo stubTodo;
	const TodoCreatedEvent createdEvent(stubTodo);

	SUT.Dispatch<Todo>(createdEvent);

	ASSERT_TRUE(called);
}

