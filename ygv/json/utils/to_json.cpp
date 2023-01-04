#include "to_json.h"
#include "ygv/json/types/types.h"

namespace ygv
{
    namespace json
    {

        DataPtr to_json(DataPtr value)
        {
            return value;
        }

        DataPtr to_json(const std::nullptr_t &)
        {
            return std::make_shared<Null>();
        }

        DataPtr to_json(const char *value)
        {
            return std::make_shared<String>(value);
        }

        DataPtr to_json(const std::string &value)
        {
            return std::make_shared<String>(value);
        }

        DataPtr to_json(int value)
        {
            return std::make_shared<IntNumber>(value);
        }

        DataPtr to_json(float value)
        {
            return std::make_shared<FloatNumber>(value);
        }

        DataPtr to_json(double value)
        {
            return std::make_shared<FloatNumber>(value);
        }

        DataPtr to_json(bool value)
        {
            return std::make_shared<Boolean>(value);
        }

    }
}