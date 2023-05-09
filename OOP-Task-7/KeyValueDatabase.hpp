#pragma once
#include "Object.hpp"
#include <string>
#include <stdexcept>
#include <vector>
class KeyValueDatabase : public Object{
    std::vector<std::pair<std::string, int>> Pairs;
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;
    Object* clone()const;
    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    std::string to_string()const;
    void from_string(const std::string&);
    std::string debug_print()const;

};

