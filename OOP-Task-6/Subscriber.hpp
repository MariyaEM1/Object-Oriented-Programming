#pragma once
#include "Message.hpp"
#include <iostream>
#include <vector>
#include <string>

class Subscriber {
private:
	std::vector<Message>messages;

public:
	const std::string id;
	virtual ~Subscriber() = default;

	Subscriber(const std::string id);
	Message getMessages(const int) const;
	int AllMessages()const;

	//bool Empty();
	virtual Subscriber* clone()const = 0;
	void addMessage(Message);
	virtual void signal(const Message&)=0;
	virtual int read()const = 0;
};
