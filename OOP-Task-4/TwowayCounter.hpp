#pragma once
#include"Counter.hpp"
class TwowayCounter : virtual public Counter
{
public:
	TwowayCounter();
	TwowayCounter(int);
	TwowayCounter(int, unsigned int);

	void decrement();
	int getInitial() const;
};