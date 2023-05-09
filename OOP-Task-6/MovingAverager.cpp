#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string id, const size_t windowSize) : Subscriber(id), windowSize(windowSize){

}

void MovingAverager::signal(const Message& message) {
	addMessage(message);
}

int MovingAverager::read()const {
	int average = 0; 

	if (windowSize == 0)return 0;
	if (AllMessages() == 0)return 0;
	int g = (AllMessages() - windowSize - 1);
	for (int i = AllMessages() - 1; (i > g && i >= 0); i--) {

		average += getMessages(i).data;
	}
	if (int (windowSize) > AllMessages()) {
		average /= AllMessages();
	}
	else {
		average /= windowSize;
	}
	return average;
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}

