#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        template <typename ValueType>
        class Number : public Data
        {
        public:
            Number() = default;

            Number(ValueType value) : m_value(value) {}

            std::string serialize() const override final
            {
                return std::to_string(m_value);
            }

            ValueType value() const
            {
                return m_value;
            }

        private:
            ValueType m_value;
        };

        using IntNumber = Number<int>;
        using FloatNumber = Number<float>;
    }
}