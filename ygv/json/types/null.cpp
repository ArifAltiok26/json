#include "null.h"
namespace ygv
{
    namespace json
    {
        std::string Null::serialize() const
        {
            return "Null";
        }
    }
}