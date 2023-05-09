#include "Error.hpp"

Error::Error(const std::string& message)
{
	this->message = message;
}

std::string Error::get_message() const
{
	return this->message;
}

void Error::print() const
{
	std::cout << this->message << std::endl;
}

Error& Error::operator=(const Error& other)
{
	this->message = other.message;
	return *this;
}
