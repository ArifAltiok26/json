#include "object.h"
#include "string.h"
#include "null.h"
#include <map>
namespace json
{
    bool operator<(const String &lhs, const String &rhs)
    {
        return lhs.value() < rhs.value();
    }

    class Object::Impl
    {

    public:
        using Container = std::map<String, DataPtr>;

        DataPtr &at(const std::string &key)
        {
            auto iter = container.emplace(key, std::make_shared<Null>());
            return iter.first->second;
        }

        std::string stringify() const
        {
            std::string retval;
            if (!container.empty())
            {
                Container::const_iterator iter = container.begin();
                retval += iter->first.stringify() + ":" + iter->second->stringify();
                while (++iter != container.end())
                {
                    retval += ", " + iter->first.stringify() + ":" + iter->second->stringify();
                }
            }

            return "{" + retval + "}";
        }

    private:
        Container container;
    };

    Object::Object()
    {
        impl = new Impl;
    }

    Object::~Object()
    {
        delete impl;
    }

    DataPtr &Object::operator[](const std::string &key)
    {
        return impl->at(key);
    }

    std::string Object::stringify() const
    {
        return impl->stringify();
    }

} // namespace json
