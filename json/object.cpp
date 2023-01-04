#include "object.h"
#include "string.h"
#include "null.h"
#include <map>
#include <algorithm>
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

        std::vector<std::string> keys() const
        {
            std::vector<std::string> retval;
            std::transform(container.begin(), container.end(), std::back_inserter(retval), [](const Container::value_type &item)
                           { return item.first.value(); });
            return retval;
        }

        bool exists(const std::string &key)
        {
            auto iter = container.find(key);
            return iter != container.end();
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

    DataPtr &Object::at(const std::string &key)
    {
        return impl->at(key);
    }

    DataPtr &Object::operator[](const std::string &key)
    {
        return at(key);
    }

    std::string Object::stringify() const
    {
        return impl->stringify();
    }

    std::vector<std::string> Object::keys() const
    {
        return impl->keys();
    }

    bool Object::exists(const std::string &key) const
    {
        return impl->exists(key);
    }

} // namespace json
