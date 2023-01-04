#include "stringify.h"
namespace ygv
{
    namespace json
    {
        std::string stringify(const Serializable &serializable)
        {
            return serializable.serialize();
        }

        std::ostream &operator<<(std::ostream &out, const Serializable &serializable)
        {
            out << stringify(serializable);
            return out;
        }
    } // namespace json

} // namespace ygv
