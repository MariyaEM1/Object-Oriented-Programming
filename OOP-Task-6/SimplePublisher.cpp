#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber*other)
{
	subscribers.push_back(other);
}

void SimplePublisher::unsubscribe(Subscriber*other)
{
	for (unsigned int i = 0; i < subscribers.size(); i++) {
		if (other->id == subscribers[i]->id) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::signal(const Message& mess)
{
	for (unsigned int i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(mess);
	}
}
