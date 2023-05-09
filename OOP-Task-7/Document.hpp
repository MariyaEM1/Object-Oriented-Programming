#pragma once
#include "Object.hpp"
#include <string>
#include <vector>

class Document : public Object{
    std::vector<std::string> lines;
    int numLines = 0;

public:
    Document(const std::string& name, const std::string& location, const std::string& extension);
    void write_line(const std::string& line);
    
    Object* clone() const;
    std::string read_line();
    std::string read_line(const unsigned line);
    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    std::string to_string()const;
    void from_string(const std::string&);
    std::string debug_print()const;

};