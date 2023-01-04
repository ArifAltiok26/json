#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class String : public Data
        {
        public:
            String();

            String(const char *value);

            String(const std::string &value);

            std::string serialize() const override final;

            std::string value() const;

            bool operator==(const String &other) const;

        private:
            std::string m_value;
        };
    }
}