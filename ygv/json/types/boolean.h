#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class Boolean : public Data
        {
        public:
            Boolean();

            Boolean(bool value);

            std::string serialize() const override final;

            bool value() const;

        private:
            bool m_value;
        };
    }
}