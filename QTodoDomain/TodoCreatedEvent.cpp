#include "Todo.h"
#include "TodoCreatedEvent.h"

using std::string;

namespace QTodo {
namespace Domain {

TodoCreatedEvent::TodoCreatedEvent(Todo newTodo) :DomainEvent<Todo>(newTodo) { }

const char* TodoCreatedEvent::GetEventType() const
{
	return EVENT_TYPE;
}

}}
