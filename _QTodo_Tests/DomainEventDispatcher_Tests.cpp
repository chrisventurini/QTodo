#include "gtest/gtest.h";

#include "QTodoDomain.h"

using QTodo::Domain::DomainEvent;
using QTodo::Domain::DomainEventDispatcher;
using QTodo::Domain::Todo;
using QTodo::Domain::TodoCreatedEvent;

TEST(DomainEventDispatcher, WhenSubscribing_WithAFunction_ShouldBeCalledWhenDispatched)
{
	DomainEventDispatcher SUT;

	bool called(false);

	SUT.Subscribe<Todo>(TodoCreatedEvent::EVENT_TYPE, [&](DomainEvent<Todo>&)
	{
		called = true;
	});

	Todo newTodo;
	TodoCreatedEvent created_event(&newTodo);

	SUT.Dispatch<Todo>(created_event);

	ASSERT_TRUE(called);
}

