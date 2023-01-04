#pragma once
#include "ygv/json/core/serializable.h"
#include <ostream>
namespace ygv
{
    namespace json
    {
        std::string stringify(const Serializable &serializable);
        std::ostream &operator<<(std::ostream &out, const Serializable &serializable);
    } // namespace json

} // namespace ygv
