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

	TodoCreatedEvent created_event;
	SUT.Dispatch(created_event);

	ASSERT_TRUE(called);
}

