#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id), period(period){
	
}
void PeriodicSampler::signal(const Message& message){
	addMessage(message);
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}

int PeriodicSampler::read()const{
	if (AllMessages() == 0)return 0;
	for (int i = AllMessages() - 1 ; i >= 0 ; i--) {
		if (i % period == 0) {
			return getMessages(i).data;
		}
	}
}
