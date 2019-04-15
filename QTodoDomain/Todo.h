#pragma once

#include <string>

namespace QTodo {
namespace Domain {

struct Todo
{
	Todo() = default;
	Todo(const std::string newTitle)
		:title(newTitle)
	{
	}

	std::string title;
};

}}
