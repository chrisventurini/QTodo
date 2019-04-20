#pragma once

#include <string>

namespace QTodo {
namespace Domain {

	struct Todo
	{
		Todo() = default;
		explicit Todo(std::string newTitle);

		bool operator==(const Todo& other) const;

		std::string title;
	};

}}
