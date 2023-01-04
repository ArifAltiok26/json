#include "from_json.h"
#include <cstring>
#include "ygv/json/types/types.h"
namespace ygv
{
    namespace json
    {

        bool from_json(const DataPtr &data, const char *&value)
        {
            const auto ptr = std::dynamic_pointer_cast<String>(data);
            if (!ptr)
                return false;
            std::string str = ptr->value();
            memcpy((void *)value, str.c_str(), str.size());
            return true;
        }

        bool from_json(const DataPtr &data, std::string &value)
        {
            return from_json<String>(data, value);
        }

        bool from_json(const DataPtr &data, int &value)
        {
            return from_json<IntNumber>(data, value);
        }

        bool from_json(const DataPtr &data, float &value)
        {
            return from_json<FloatNumber>(data, value);
        }

        bool from_json(const DataPtr &data, double &value)
        {
            return from_json<FloatNumber>(data, value);
        }

        bool from_json(const DataPtr &data, bool &value)
        {
            return from_json<Boolean>(data, value);
        }

    }
}