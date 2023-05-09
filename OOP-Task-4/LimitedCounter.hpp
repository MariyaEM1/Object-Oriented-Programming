#pragma once
#include"Counter.hpp"

class LimitedCounter : virtual public Counter
{
private:
	int max;

public:
	LimitedCounter(int);
	LimitedCounter(int, int);
	LimitedCounter(int, int, unsigned int);

	void increment();
	int getMax()const;
};