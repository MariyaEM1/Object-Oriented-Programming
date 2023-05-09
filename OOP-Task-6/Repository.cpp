#include "Repository.hpp"


Repository::Repository(const Repository& other)
{
	copy(other);
}
Repository& Repository::operator=(const Repository& other)
{
	if (this != &other)
	{
		deleteAll();
		copy(other);
	}
	return *this;
}
void Repository::deleteAll()
{
	for (auto x : subscribers)
	{
		delete x;
	}
	subscribers.clear();
}
Repository::~Repository()
{
	deleteAll();
}
void Repository::copy(const Repository& other)
{
	for (auto x : other.subscribers)
	{
		subscribers.push_back(x->clone());
	}
}

void Repository::add(const Subscriber* other) {
	const Averager* averagerptr = dynamic_cast<const Averager*>(other);
	if (averagerptr) {
		subscribers.push_back(new Averager(*averagerptr));
	}
	const MovingAverager* movingAveragerptr = dynamic_cast<const MovingAverager*>(other);
	if (movingAveragerptr) {
		subscribers.push_back(new MovingAverager(*movingAveragerptr));
	}
	const PeriodicSampler* periodicSamplerptr = dynamic_cast<const PeriodicSampler*>(other);
	if (periodicSamplerptr) {
		subscribers.push_back(new PeriodicSampler(*periodicSamplerptr));
	}
}

Subscriber* Repository::get(std::string id) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == id) {
			return subscribers[i];
		}
	}
	return nullptr;
}
