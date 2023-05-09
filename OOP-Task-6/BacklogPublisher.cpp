#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* other)
{
	SimplePublisher::subscribe(other);
	for (unsigned int i = 0; i < mes.size(); i++) {
	other->signal(mes[i]);
	}
}
void BacklogPublisher::signal(const Message& m)
{
	mes.push_back(m);
	SimplePublisher::signal(m);
}