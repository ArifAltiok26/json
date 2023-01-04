#include "object.h"
#include "null.h"
#include <algorithm>

namespace ygv
{
    namespace json
    {

        using Container = Object::Container;

        std::string Object::serialize() const
        {
            std::string retval;

            if (!m_elements.empty())
            {
                auto iter = m_elements.begin();
                auto to_string = [](const decltype(iter) &item)
                {
                    return item->first.serialize() + ":" + item->second->serialize();
                };

                retval += to_string(iter);
                while (++iter != m_elements.end())
                {
                    retval += ", " + to_string(iter);
                }
            }

            return "{" + retval + "}";
        }

        std::vector<std::string> Object::keys() const
        {
            std::vector<std::string> retval;
            std::transform(m_elements.begin(), m_elements.end(), std::back_inserter(retval), [](const Container::value_type &item)
                           { return item.first.value(); });
            return retval;
        }

        bool Object::exists(const std::string &key) const
        {
            return m_elements.find(key) != m_elements.end();
        }

        DataPtr &Object::operator[](const std::string &key)
        {
            auto inserted = m_elements.emplace(key, std::make_shared<Null>());
            return inserted.first->second;
        }

        const DataPtr Object::operator[](const std::string &key) const
        {
            static DataPtr NullObject = std::make_shared<Null>();
            auto iter = m_elements.find(key);
            return iter != m_elements.end() ? iter->second : NullObject;
        }

    }
}