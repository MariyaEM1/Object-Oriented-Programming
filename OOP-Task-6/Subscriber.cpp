#include "Subscriber.hpp"

Subscriber::Subscriber(std::string id) : id(id){

}
Message Subscriber::getMessages(const int index) const
{
	return messages[index];
}
int Subscriber::AllMessages() const
{
	return messages.size();
}
/*bool Subscriber::Empty() {
	if (messages.size() == 0) return 0;
	else return 1;
}*/
void Subscriber::addMessage(Message m)
{
	messages.push_back(m);
}

