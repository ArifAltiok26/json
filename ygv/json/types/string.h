#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class String : public Data
        {
        public:
            String() = default;

            String(const char *value) : m_value(value) {}

            String(const std::string &value) : m_value(value) {}

            std::string serialize() const override final
            {
                return "\"" + m_value + "\"";
            }

            std::string value() const
            {
                return m_value;
            }

            bool operator==(const String &other) const
            {
                return m_value == other.m_value;
            }

        private:
            std::string m_value;
        };
    }
}