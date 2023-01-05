#pragma once
#include "ygv/json/core/data.h"
#include <stdexcept>
#include "ygv/json/variable.h"
namespace ygv
{
    namespace json
    {
        struct FromJsonMethodNotImplemented : public std::runtime_error
        {
            using std::runtime_error::runtime_error;
        };

        class Variable;

        template <typename ValueType>
        bool from_json(const Variable &variable, ValueType value)
        {
            throw FromJsonMethodNotImplemented(std::string("class of ") + typeid(value).name());
        }

        template <typename JsonType, typename ValueType>
        bool from_json(const DataPtr &data, ValueType &value)
        {
            auto ptr = std::dynamic_pointer_cast<JsonType>(data);
            if (!ptr)
                return false;
            value = ptr->value();
            return true;
        }

        bool from_json(const DataPtr &data, const char *&value);

        bool from_json(const DataPtr &data, std::string &value);

        bool from_json(const DataPtr &data, int &value);

        bool from_json(const DataPtr &data, float &value);

        bool from_json(const DataPtr &data, double &value);

        bool from_json(const DataPtr &data, bool &value);

        template <typename ValueType>
        bool from_json_key(const Variable &variable, const std::string &key, ValueType &value)
        {
            if (!variable.exists(key))
                return false;
            return from_json(*variable[key], value);
        }

    }
}