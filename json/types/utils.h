#pragma once
#include <iostream>
#include "data.h"
namespace json
{
    std::string stringify(const Data &data);
}

std::ostream &operator<<(std::ostream &out, const json::Data &data);
