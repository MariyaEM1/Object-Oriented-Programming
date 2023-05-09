#pragma once
#include"LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter
{
private:
	int min;
public:
	LimitedTwowayCounter(int, int);
	LimitedTwowayCounter(int, int, int);
	LimitedTwowayCounter(int, int, int, unsigned int);
	void decrement();
	int getMin() const;
};