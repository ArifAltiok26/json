#pragma once
#include "ygv/json/core/data.h"
#include <unordered_map>
#include "string.h"
#include "null.h"
#include <vector>
#include <algorithm>
namespace std
{
    template <>
    struct hash<ygv::json::String>
    {
        std::size_t operator()(const ygv::json::String &str) const
        {
            static hash<std::string> h;
            return h(str.value());
        }
    };
}

namespace ygv
{
    namespace json
    {

        class Object : public Data
        {
        public:
            using Container = std::unordered_map<String, DataPtr>;

            std::string serialize() const override final
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

            std::vector<std::string>
            keys() const
            {
                std::vector<std::string> retval;
                std::transform(m_elements.begin(), m_elements.end(), std::back_inserter(retval), [](const Container::value_type &item)
                               { return item.first.value(); });
                return retval;
            }

            bool exists(const std::string &key) const
            {
                return m_elements.find(key) != m_elements.end();
            }

            DataPtr &operator[](const std::string &key)
            {
                auto inserted = m_elements.emplace(key, std::make_shared<Null>());
                return inserted.first->second;
            }

            const DataPtr operator[](const std::string &key) const
            {
                static DataPtr NullObject = std::make_shared<Null>();
                auto iter = m_elements.find(key);
                return iter != m_elements.end() ? iter->second : NullObject;
            }

        private:
            std::unordered_map<String, DataPtr> m_elements;
        };
    }
}