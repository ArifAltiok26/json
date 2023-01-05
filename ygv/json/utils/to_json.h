#pragma once
#include "ygv/json/core/data.h"
#include <stdexcept>
namespace ygv
{
    namespace json
    {

        struct ToJsonMethodNotImplemented : public std::runtime_error
        {
            using std::runtime_error::runtime_error;
        };

        template <typename ValueType>
        DataPtr to_json(ValueType value)
        {
            throw ToJsonMethodNotImplemented(std::string("class of ") + typeid(value).name());
        }

        DataPtr to_json(DataPtr value);

        DataPtr to_json(const std::nullptr_t &);

        DataPtr to_json(const char *value);

        DataPtr to_json(const std::string &value);

        DataPtr to_json(int value);

        DataPtr to_json(float value);

        DataPtr to_json(double value);

        DataPtr to_json(bool value);
    }
}