#pragma once
#include "data.h"
namespace json
{
    class Null : public Data
    {
    public:
        std::string stringify() const override final;
    };
} // namespace json
