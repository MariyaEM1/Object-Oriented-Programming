#pragma once
class Counter 
{
protected:
	int initial;
	unsigned int step;

public:
	Counter();
	Counter(int);
	Counter(int, unsigned int);

	void increment();

	int getTotal()const;
	unsigned int getStep()const;

};