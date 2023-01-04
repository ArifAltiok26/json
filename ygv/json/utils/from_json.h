#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class Variable;

        template <typename ValueType>
        bool from_json(const Variable &variable, ValueType value)
        {
            throw std::runtime_error(std::string("Not Implemented to_json function for class of ") + typeid(value).name());
        }

        template <typename JsonType, typename ValueType>
        bool from_json(const DataPtr &data, ValueType value)
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

    }
}