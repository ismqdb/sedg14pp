/* ******************************************************************************** */

#include "result.hpp"

/* ******************************************************************************** */

template <typename T>
    result<T> result<T>::success(T value) {
        return result(value, std::nullopt);
    }

/* ******************************************************************************** */

template <typename T>
    result<T> result<T>::error(std::string error_message) {
        return result(std::nullopt, error_message);
    }

/* ******************************************************************************** */

template <typename T>
    bool result<T>::isSuccess() const {
        return value_.has_value();
    }

/* ******************************************************************************** */

template <typename T>
    const T& result<T>::value() const {
        if (!isSuccess()) {
            throw std::logic_error("Accessing value of an error result.");
        }
        return value_.value();
    }

/* ******************************************************************************** */

template <typename T>
    const std::string& result<T>::errorMessage() const {
        if (isSuccess()) {
            throw std::logic_error("Accessing error message of a success result.");
        }
        return error_message_.value();
    }

/* ******************************************************************************** */