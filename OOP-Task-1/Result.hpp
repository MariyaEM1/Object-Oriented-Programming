#pragma once
#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const T& other) const;
    bool operator==(const Error& other) const;

private:
    bool isT;
    Optional<T> result;
    Optional<Error> error_message;
};

template<typename T>
Result<T>::Result()
{
    isT = 1;
}

template<typename T>
Result<T>::Result(const T& result)
{
    isT = 1;
    this->result.setValue(result);
}

template<typename T>
inline Result<T>::Result(const std::string& error_message)
{
    isT = 0;
    this->error_message = Optional<Error>(Error(error_message));
}

template<typename T>
inline Optional<T> Result<T>::get_result() const
{
    return this->result;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const
{
    return this->error_message;
}

template<typename T>
inline bool Result<T>::operator==(const T& other) const
{
    if (isT == 1) {
        return true;
    }
    return false;
}
template<typename T>
inline bool Result<T>::operator==(const Error& other) const
{
    if (isT == 0)return true;
    return false;
}
