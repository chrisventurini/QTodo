#include "DomainEventDispatcher.h"

#include <memory>
#include <string>

#include "boost/any.hpp"
#include "boost/signals2.hpp"
#include "TodoCreatedEvent.h"

using boost::any;
using boost::any_cast;
using boost::signals2::signal;
using std::make_shared;
using std::function;
using std::shared_ptr;
using std::string;




