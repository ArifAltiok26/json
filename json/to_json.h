#pragma once
#include "object.h"
#include "array.h"

template <typename ValueType>
void to_object(json::Object &object, const ValueType &value);

namespace json
{

    class Variable;

    struct ToObjectNotImplemented : std::runtime_error
    {
        using std::runtime_error::runtime_error;
    };

    template <typename ValueType>
    DataPtr to_json(ValueType value);

    template <>
    DataPtr to_json<const char *>(const char *value);

    template <>
    DataPtr to_json<std::string>(std::string value);

    template <>
    DataPtr to_json<std::nullptr_t>(std::nullptr_t);

    template <>
    DataPtr to_json<int>(int value);

    template <>
    DataPtr to_json<long>(long value);

    template <>
    DataPtr to_json<float>(float value);

    template <>
    DataPtr to_json<double>(double value);

    template <>
    DataPtr to_json<bool>(bool value);

    template <>
    DataPtr to_json<Variable>(Variable variable);

    template <>
    DataPtr to_json<Variable &&>(Variable &&variable);

    template <typename ValueType>
    DataPtr to_json(const std::vector<ValueType> &values);

    template <typename ValueType>
    void to_array(Array &array, const std::vector<ValueType> &values);

    ///////////////////////////////////////////

    template <typename ValueType>
    DataPtr to_json(ValueType value)
    {
        std::shared_ptr<Object> retval = std::make_shared<Object>();
        to_object(*retval, value);
        return retval;
    }

    template <typename ValueType>
    DataPtr to_json(const std::vector<ValueType> &values)
    {
        std::shared_ptr<Array> retval = std::make_shared<Array>();
        to_array(*retval, values);
        return retval;
    }

    template <typename ValueType>
    void to_array(Array &array, const std::vector<ValueType> &values)
    {
        for (int i = 0; i < values.size(); i++)
        {
            array[i] = to_json(values[i]);
        }
    }

} // namespace json

#include <typeindex>
template <typename ValueType>
void to_object(json::Object &object, const ValueType &value)
{
    std::string type = typeid(value).name();
    throw json::ToObjectNotImplemented("to_object not implemented function for type of " + type);
}
