#include "Todo.h"
#include <utility>

using std::string;

namespace QTodo {
namespace Domain {

	Todo::Todo(string newTitle) : title(std::move(newTitle)) { }

	bool Todo::operator==(const Todo& other) const
	{
		return other.title == title;
	}

}}
