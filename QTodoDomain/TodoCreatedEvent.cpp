#include "Todo.h"
#include "TodoCreatedEvent.h"

using std::string;

namespace QTodo {
namespace Domain {

string TodoCreatedEvent::GetEventType() const
{
	return EVENT_TYPE;
}

Todo TodoCreatedEvent::GetPayload() const
{
	return Todo();
}

}}
