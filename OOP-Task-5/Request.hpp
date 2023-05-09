#pragma once
#include <string>
using namespace std;

class Request 
{
private:
	string message;
	string sender;
	static int counter;
	int ID;

public:
	Request(const string&, const string&);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};