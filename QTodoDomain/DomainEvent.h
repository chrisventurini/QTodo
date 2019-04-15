#pragma once

namespace QTodo {
namespace Domain {

template <typename T>
class DomainEvent
{
public:
	DomainEvent() = default;
	DomainEvent(T* payload): payload_(payload) {};

	virtual ~DomainEvent() = default;

	virtual const char* GetEventType() const = 0;
	virtual T* GetPayload() const { return payload_; };
	virtual void SetPayload(T* payload) { payload_ = payload; }
protected:
	T* payload_;
};

}}
