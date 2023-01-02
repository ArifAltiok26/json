#pragma once
#include "data.h"
namespace json
{
    class Boolean : public Data
    {
    public:
        Boolean();

        Boolean(bool value);

        std::string stringify() const override final;

        bool value() const;

    private:
        bool m_value;
    };
}