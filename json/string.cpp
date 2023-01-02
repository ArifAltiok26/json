#include "string.h"
namespace json
{
    String::String(const char *value) : m_value(value) {}
    std::string String::stringify() const { return "\"" + m_value + "\""; }

} // namespace json
