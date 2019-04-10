#pragma once

#include "DomainEvent.h"
#include "todo.h"

namespace QTodo {
namespace Domain {

class TodoCreatedEvent : public DomainEvent<Todo>
{
public:
	static constexpr auto EVENT_TYPE = "TODO_CREATED";

	std::string GetEventType() const override;
	Todo GetPayload() const override;
};


}}
