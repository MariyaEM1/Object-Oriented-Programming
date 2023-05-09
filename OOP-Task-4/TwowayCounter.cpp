#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter() : Counter()
{

}
TwowayCounter::TwowayCounter(int initial) : Counter(initial)
{

}
TwowayCounter::TwowayCounter(int initial, unsigned int step) : Counter(initial, step)
{

}

void TwowayCounter::decrement() 
{
	initial -= step;
}
int TwowayCounter::getInitial() const
{
	return initial;
}
