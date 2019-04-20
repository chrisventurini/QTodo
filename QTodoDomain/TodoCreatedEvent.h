#pragma once

#include "DomainEvent.h"
#include "Todo.h"

namespace QTodo {
namespace Domain {

	class TodoCreatedEvent : public DomainEvent<Todo>
	{
	public:
		explicit TodoCreatedEvent(Todo newTodo);

		static constexpr const char* EVENT_TYPE = "TODO_CREATED";

		const char* GetEventType() const override;
	};

}}
