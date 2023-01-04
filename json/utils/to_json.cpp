#include "to_json.h"
#include "types.h"
#include "variable.h"

namespace json
{

    template <>
    DataPtr to_json<const char *>(const char *value)
    {
        return std::make_shared<String>(value);
    }

    template <>
    DataPtr to_json<std::string>(std::string value)
    {
        return std::make_shared<String>(value);
    }

    template <>
    DataPtr to_json<std::nullptr_t>(std::nullptr_t)
    {
        return std::make_shared<Null>();
    }

    template <>
    DataPtr to_json<int>(int value)
    {
        return std::make_shared<Number>(value);
    }

    template <>
    DataPtr to_json<long>(long value)
    {
        return std::make_shared<Number>(value);
    }

    template <>
    DataPtr to_json<float>(float value)
    {
        return std::make_shared<Number>(value);
    }

    template <>
    DataPtr to_json<double>(double value)
    {
        return std::make_shared<Number>(value);
    }

    template <>
    DataPtr to_json<bool>(bool value)
    {
        return std::make_shared<Boolean>(value);
    }

    template <>
    DataPtr to_json<Variable>(Variable variable)
    {
        return variable.m_data;
    }

    template <>
    DataPtr to_json<Variable &&>(Variable &&variable)
    {
        return variable.m_data;
    }

} // namespace json
