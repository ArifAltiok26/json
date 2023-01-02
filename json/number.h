#pragma once
#include "data.h"
namespace json
{
    class Number : public Data
    {
    public:
        Number();
        Number(int value);
        Number(float value);
        ~Number();

        Number &operator=(int value);
        Number &operator=(float value);

        std::string stringify() const override final;

    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
