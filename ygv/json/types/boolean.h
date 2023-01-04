#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class Boolean : public Data
        {
        public:
            Boolean() = default;

            Boolean(bool value) : m_value(value) {}

            std::string serialize() const override final
            {
                return m_value ? "true" : "false";
            }

            bool value() const
            {
                return m_value;
            }

        private:
            bool m_value;
        };
    }
}