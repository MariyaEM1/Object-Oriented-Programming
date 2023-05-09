#pragma once
#include "Subscriber.hpp"
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <vector>

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// Repository is the single place where Subscribers will
// be stored. A Repository has ownership of the Subscribers
// stored inside it.
// The only way to access the available Subscribers in the
// repository is via the Subscriber's unique id.
// id's are guaranteed to be unique
class Repository {
	std::vector<Subscriber*>subscribers;
public:
	Repository()=default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	~Repository();
	void copy(const Repository&);
	void deleteAll();
	void add(const Subscriber* other);
	Subscriber* get(std::string id);
};