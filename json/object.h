#pragma once
#include "data.h"
namespace json
{
    class Object : public Data
    {
    public:
    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
