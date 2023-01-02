#pragma once
#include "data.h"
namespace json
{
    class String : public Data
    {
    public:
        String(const char *value);

        String(const std::string &value);

        std::string stringify() const override final;

        std::string value() const;

    private:
        std::string m_value;
    };
} // namespace json
