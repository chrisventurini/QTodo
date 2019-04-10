#pragma once

#include <string>

namespace QTodo {
namespace Domain {

template <typename T>
class DomainEvent
{
public:
	virtual std::string GetEventType() const = 0;
	virtual T GetPayload() const { return _payload; };
	virtual void SetPayload(T payload) { _payload = payload; }
private:
	T _payload;
};

}}
