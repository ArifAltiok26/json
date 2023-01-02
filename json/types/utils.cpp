#include "utils.h"
namespace json
{
    std::string stringify(const Data &data)
    {
        return data.stringify();
    }
}

std::ostream &operator<<(std::ostream &out, const json::Data &data)
{
    out << json::stringify(data);
    return out;
}