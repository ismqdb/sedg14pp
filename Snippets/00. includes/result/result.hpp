/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <string>
#include <optional>

#include "../types.hpp"

/* ******************************************************************************** */

template <typename T>
    class result {
        public:
            static result success(T);
            static result error(std::string);
            bool isSuccess() const;
            const T& value() const;
            const std::string& errorMessage() const;

        private:
            result(std::optional<T>, std::optional<std::string>);

            std::optional<T> value_;
            std::optional<std::string> error_message_;
    };

/* ******************************************************************************** */

template class result<i32>;

/* ******************************************************************************** */