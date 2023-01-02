#pragma once
#include <ostream>
#include "data.h"
#include "data_fwd.h"
namespace json
{
    std::string stringify(const Data &data);

    DataPtr convert(const char *value);

    DataPtr convert(int value);

    DataPtr convert(float value);

    DataPtr convert(double value);

    DataPtr convert(bool value);
}

std::ostream &operator<<(std::ostream &out, const json::Data &data);
