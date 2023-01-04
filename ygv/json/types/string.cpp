#include "string.h"
namespace ygv
{
    namespace json
    {
        String::String() = default;

        String::String(const char *value) : m_value(value) {}

        String::String(const std::string &value) : m_value(value) {}

        std::string String::serialize() const
        {
            return "\"" + m_value + "\"";
        }

        std::string String::value() const
        {
            return m_value;
        }

        bool String::operator==(const String &other) const
        {
            return m_value == other.m_value;
        }
    }
}