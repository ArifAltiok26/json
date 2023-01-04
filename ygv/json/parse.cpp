#include "parse.h"
#include "ygv/json/types/types.h"
namespace ygv
{
    namespace json
    {
        DataPtr parse(const std::string &content)
        {
            return std::make_shared<Null>();
        }
    } // namespace json
} // namespace ygv
