#pragma once
#include<iostream>
#include "Error.hpp" 
template <typename T>

class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
    void setValue(const T& other);

    void print();
private:
    T value;
    bool isEmpty;
};

template<typename T>
Optional<T>::Optional()
{
    this->isEmpty = true;
    this->value = T();
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->isEmpty = false;
    this->value = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
    return isEmpty;
}

template<typename T>
T Optional<T>::get_value() const
{
    return this->value;
}

template<typename T>
void Optional<T>::setValue(const T& other)
{
    isEmpty = false;
    this->value = other;
}

template<typename T>
void Optional<T>::print()
{
    std::cout << this->value << std::endl;
}
