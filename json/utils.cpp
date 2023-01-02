#include "utils.h"
#include "string.h"
#include "number.h"
#include "boolean.h"
#include "null.h"
namespace json
{
    std::string stringify(const Data &data)
    {
        return data.stringify();
    }

    DataPtr convert(const char *value)
    {
        if (value)
            return std::make_shared<String>(value);
        return std::make_shared<Null>();
    }

    DataPtr convert(int value)
    {
        return std::make_shared<Number>(value);
    }

    DataPtr convert(float value)
    {
        return std::make_shared<Number>(value);
    }

    DataPtr convert(double value)
    {
        return std::make_shared<Number>(value);
    }

    DataPtr convert(bool value)
    {
        return std::make_shared<Boolean>(value);
    }
}

std::ostream &operator<<(std::ostream &out, const json::Data &data)
{
    out << json::stringify(data);
    return out;
}