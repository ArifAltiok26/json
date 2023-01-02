#pragma once
#include "data.h"
namespace json
{
    class String : public Data
    {
    public:
        String(const char *value);

        std::string stringify() const override final;

    private:
        std::string m_value;
    };
} // namespace json
