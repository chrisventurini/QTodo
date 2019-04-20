#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "boost/any.hpp"
#include "boost/signals2.hpp"

#include "DomainEvent.h"


namespace QTodo {
namespace Domain {

	template<typename T>
	using signal_ptr = std::shared_ptr<boost::signals2::signal<void(const DomainEvent<T>&)>>;

class DomainEventDispatcher
{
public:
	template<class T>
	void Dispatch(const DomainEvent<T>& event);

	template<class T>
	void Subscribe(const char* eventType, std::function<void(const DomainEvent<T>&)> slot);

private:
	template<class T>
	signal_ptr<T> get_signal(const char* eventType);

	std::unordered_map<const char*, boost::any> _signals;
};

}}

#include "DomainEventDispatcher.inl.h"
