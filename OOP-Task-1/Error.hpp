#pragma once
#include <string>
#include <iostream>
class Error {
public:
    Error(const std::string& message = "");
    std::string get_message() const;
    void print() const;
    Error& operator=(const Error& other);

private:
    std::string message;
};
