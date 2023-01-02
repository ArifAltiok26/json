#include "boolean.h"
namespace json
{

    Boolean::Boolean() = default;

    Boolean::Boolean(bool value) : m_value(value) {}

    std::string Boolean::stringify() const
    {
        return m_value ? "true" : "false";
    }

    bool Boolean::value() const
    {
        return m_value;
    }

}