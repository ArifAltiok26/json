#pragma once
#include "variable.h"
#include <istream>
namespace ygv
{
    namespace json
    {
        Variable parse(const std::string &content);

        Variable parse(std::istream &input);
    } // namespace json

} // namespace ygv
