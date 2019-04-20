#pragma once

namespace QTodo {
namespace Domain {

	template<typename T>
	DomainEvent<T>::DomainEvent(T payload): payload_(std::move(payload)) {};

	template<typename T>
	boost::optional<T> DomainEvent<T>::GetPayload() const { return payload_; };

	template<typename T>
	void DomainEvent<T>::SetPayload(T payload) { payload_ = payload; }

	template <typename T>
	bool DomainEvent<T>::operator==(const DomainEvent<T>& other) const
	{
		if(other.GetEventType() != GetEventType()) { return false; }

		return other.payload_ == payload_;
	}
	
}}
