#include"LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : Counter(), LimitedCounter(max), TwowayCounter(), min(min)
{
}
LimitedTwowayCounter::LimitedTwowayCounter(const int min, int max, int initial) : Counter(initial), LimitedCounter(max, initial), TwowayCounter(initial), min(min)
{
}
LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step) : Counter(initial, step), LimitedCounter(max, initial, step), TwowayCounter(initial, step), min(min)
{
}
void LimitedTwowayCounter::decrement()
{
	if (int(initial) - int(step) >= min) {
		TwowayCounter::decrement();
	}
}
int LimitedTwowayCounter::getMin() const
{
	return min;
}
