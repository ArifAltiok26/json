#include "boolean.h"
namespace ygv
{
    namespace json
    {
        Boolean::Boolean() = default;

        Boolean::Boolean(bool value) : m_value(value) {}

        std::string Boolean::serialize() const
        {
            return m_value ? "true" : "false";
        }

        bool Boolean::value() const
        {
            return m_value;
        }
    }
}