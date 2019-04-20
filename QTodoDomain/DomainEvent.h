#pragma once

#include <boost/optional/optional.hpp>

namespace QTodo {
namespace Domain {

	template <typename T>
	class DomainEvent
	{
	public:
		DomainEvent() = default;
		DomainEvent(T payload);

		virtual ~DomainEvent() = default;

		virtual const char* GetEventType() const = 0;
		virtual boost::optional<T> GetPayload() const;
		virtual void SetPayload(T payload);

		virtual bool operator==(const DomainEvent<T>& other) const;
	protected:
		boost::optional<T> payload_;
	};

}}

#include "DomainEvent.inl.h"
