#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension) : Object(name, location, extension)
{
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (unsigned int i = 0; i < Pairs.size(); i++) {

		if (Pairs[i].first == entry.first) {
			throw std::invalid_argument("invalid");
		}
	}
	Pairs.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	for (unsigned int i = 0; i < Pairs.size(); i++) {
		if (Pairs[i].first == key) {
			return Pairs[i].second;
		}
	}
	throw std::invalid_argument("invalid");
}

bool KeyValueDatabase::operator==(const Comparable* compare) const
{
	const KeyValueDatabase* keyptr = dynamic_cast<const KeyValueDatabase*>(compare);
	if (keyptr) {
		if (keyptr->Pairs.size() != this->Pairs.size()) return false;
		else if (keyptr->Pairs.size() == this->Pairs.size()) {
			for (unsigned int i = 1; i < keyptr->Pairs.size(); i++) {
				if (keyptr->Pairs[i].first != this->Pairs[i].first) {
					return false;
				}
				else if (keyptr->Pairs[i].second != this->Pairs[i].second) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool KeyValueDatabase::operator!=(const Comparable* compare) const
{
	const KeyValueDatabase* keyptr = dynamic_cast<const KeyValueDatabase*>(compare);
	if (keyptr) {
		return !(*this == compare);
	}
	return false;
}


Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

std::string KeyValueDatabase::to_string()const
{
	std::string inOneString;
	inOneString = get_name() + "\n" + get_location() + "\n" + get_extension() + "\n";

	for (unsigned int i = 0; i < Pairs.size(); i++)
	{
		std::string num = std::to_string(Pairs[i].second);
		inOneString += Pairs[i].first + ":" + num + "\n";
	}
	return inOneString;
}


void KeyValueDatabase::from_string(const std::string& inOneString)
{
	std::pair<std::string, int> p;
	std::string s = "";
	int counter1 = 1;
	for (unsigned int i = 0; inOneString[i] != '\0'; i++) {
		if (inOneString[i] == ':') {
			//s.pop_back();

			if (counter1 > 3) {
				p.first = s;
				s = "";
			}
		}
		else if (inOneString[i] == '\n') {
			//s.pop_back();
			if (counter1 > 3) {
				p.second = std::stoi(s);
				Pairs.push_back(p);
			}
			if (counter1 == 1) {
				name = s;
			}
			if (counter1 == 2) {
				location = s;
			}
			if (counter1 == 3) {
				extension = s;
			}
			s = "";
			counter1++;

		}
		else if (inOneString[i] != ':' && inOneString[i] != '\n') {

			s += inOneString[i];
		}
	}
}

std::string KeyValueDatabase::debug_print()const
{

	std::string inOneString;

	for (unsigned int i = 0; i < Pairs.size(); i++)
	{
		std::string number = std::to_string(Pairs[i].second);

		inOneString += "{" + Pairs[i].first + ":" + number + "}" + "\n";
	}
	return inOneString;
}