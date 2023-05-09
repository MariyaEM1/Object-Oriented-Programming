#pragma once
#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class MovingAverager : public Subscriber {
public:
	MovingAverager(const std::string id, const size_t windowSize);

	const size_t windowSize;
	void signal(const Message&);
	int read()const;
	Subscriber* clone() const;
};