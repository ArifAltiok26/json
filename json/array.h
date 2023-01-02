#pragma once
#include "data.h"
namespace json
{
    class Array : public Data
    {
    public:
    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
