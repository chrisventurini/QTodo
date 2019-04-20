#pragma once

namespace QTodo {
namespace Domain {

	template <typename T>
	void DomainEventDispatcher::Dispatch(const DomainEvent<T>& event)
	{
		get_signal<T>(event.GetEventType())->operator()(event);
	}

	template <typename T>
	void DomainEventDispatcher::Subscribe(const char* eventType, std::function<void(const DomainEvent<T>&)> slot)
	{
		get_signal<T>(eventType)->connect(slot);
	}

	// Private methods 
	template <typename T>
	signal_ptr<T> DomainEventDispatcher::get_signal(const char* eventType)
	{
		const auto slotIter = _signals.find(eventType);

		if (slotIter == _signals.end())
		{
			auto newEventSignal = std::make_shared<boost::signals2::signal<void(const DomainEvent<T>&)>>();

			_signals.insert({ eventType, newEventSignal });
		}

		boost::any boxedSignal = _signals[eventType];

		return boost::any_cast<signal_ptr<T>>(boxedSignal);
	}

}}
