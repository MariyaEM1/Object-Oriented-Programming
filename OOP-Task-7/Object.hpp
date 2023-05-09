#pragma once
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"
#include <string>

class Object : public Comparable, public Debug, public Serializable {
protected:
    std::string name;
    std::string location;
    std::string extension;
public:
    virtual ~Object()=default;
    Object(const std::string& name, const std::string& location, const std::string& extension);

    virtual Object* clone() const = 0;
    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
};