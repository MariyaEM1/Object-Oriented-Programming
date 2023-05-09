#include "Counter.hpp"
//da poopravq current ako izobshto shte mi trqbva

Counter::Counter() : initial(0), step(1)
{

}
Counter::Counter(int initial) : initial(initial), step(1)
{

}
Counter::Counter( int initial, unsigned int step) :initial(initial), step(step)
{

}
void Counter::increment() 
{
	initial += step;
}
int Counter::getTotal() const
{
	return initial;
}
unsigned int Counter::getStep() const
{
	return step;
}
