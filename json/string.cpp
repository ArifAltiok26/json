#include "string.h"
namespace json
{
    String::String(const char *value) : m_value(value) {}

    String::String(const std::string &value) : m_value(value) {}

    std::string String::stringify() const
    {
        return "\"" + m_value + "\"";
    }

    std::string String::value() const
    {
        return m_value;
    }
} // namespace json
