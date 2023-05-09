#include "Document.hpp"
#include <stdexcept>

Document::Document(const std::string& name, const std::string& location, const std::string& extension) : Object(name, location, extension)
{

}

void Document::write_line(const std::string& line)
{
	lines.push_back(line);
}

Object* Document::clone() const
{
	return new Document(*this);
}

std::string Document::read_line()
{
	if (lines.size() == 0 && numLines > (int(lines.size()) - 1)) {
		throw  std::out_of_range("Nothing to read");
	}
	numLines++;
	return lines[numLines-1];
}

std::string Document::read_line(const unsigned line)
{
	numLines = line - 1;
	if (lines.size() == 0 && numLines > (int(lines.size()) - 1)) {
		throw  std::out_of_range("Nothing to read");
	}
	numLines++;
	return lines[numLines-1];
}

bool Document::operator==(const Comparable* compare) const
{
	const Document* docptr = dynamic_cast<const Document*>(compare);
	if (docptr == nullptr) return false;
	if (docptr->lines.size() != this->lines.size()) return false;
	for (unsigned int i = 0; i < docptr->lines.size(); i++) {
		if (docptr->lines[i] != this->lines[i]) {
			return false;
		}
	}
	return true;
}

bool Document::operator!=(const Comparable* compare) const
{
	return !(*this == compare);
}

std::string Document::to_string()const
{
	std::string inOneString;
		inOneString = get_name() + "\n" + get_location() + "\n" + get_extension() + "\n";
	
	for (unsigned int i = 0; i < lines.size(); i++) 
	{
		inOneString += lines[i] + "\n";
	}
	return inOneString;
}

void Document::from_string(const std::string& inOneString)
{
	std::string s = "";
	int counter = 0;
	for (unsigned int i = 0; inOneString[i] != '\0'; i++) {
		if (inOneString[i] != '\n') {
			s += inOneString[i];
		}
		if (inOneString[i] == '\n') {
			counter++;
			if (counter == 1) {
				name = s;
			}
			if (counter == 2) {
				location = s;
			}
			if (counter == 3) {
				extension = s;
			}
			if (counter > 3) {
				lines.push_back(s);
			}
			s = "";
		}
	}
}

std::string Document::debug_print() const
{
	std::string inOneString;

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		std::string number = std::to_string(i+1);
		inOneString += "Line " + number+":" + lines[i] + "\n";
	}
	return inOneString;
}






