#include "Message.hpp"
#include "Averager.hpp"

Averager::Averager(const std::string id) : Subscriber(id) {

}
void Averager::signal(const Message& message){
	addMessage(message);
}
int Averager::read() const{
	int average = 0;
	if (AllMessages() == 0)return 0;
	for (int i =0 ; i < AllMessages(); i++) {
		average += getMessages(i).data;
	}
	average = average / AllMessages();
	return average;
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}


