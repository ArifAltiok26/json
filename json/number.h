#pragma once
#include "data.h"
namespace json
{
    class Number : public Data
    {
    public:
        Number();

        template <typename ValueType>
        Number(ValueType value);

        ~Number();

        Number &operator=(int value);
        Number &operator=(long value);
        Number &operator=(float value);
        Number &operator=(double value);

        std::string stringify() const override final;

    private:
        class Impl;
        Impl *impl;
    };

    template <typename ValueType>
    Number::Number(ValueType value) : Number()
    {
        *this = value;
    }
} // namespace json
