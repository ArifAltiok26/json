#include "convert.h"
#include "types/string.h"
#include "types/number.h"
#include "types/boolean.h"
#include "types/null.h"
namespace json
{

    DataPtr convert(const std::string &value)
    {
        return std::make_shared<String>(value);
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
