#pragma once
#include "ygv/json/core/data.h"
#include <unordered_map>
#include "string.h"
#include <vector>
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

            std::string serialize() const override final;

            std::vector<std::string> keys() const;

            bool exists(const std::string &key) const;

            DataPtr &operator[](const std::string &key);

            const DataPtr operator[](const std::string &key) const;

        private:
            std::unordered_map<String, DataPtr> m_elements;
        };
    }
}