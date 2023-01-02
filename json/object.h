#pragma once
#include "data.h"
#include "data_fwd.h"
namespace json
{
    class Object : public Data
    {
    public:
        Object();

        ~Object();

        DataPtr &operator[](const std::string &key);

        std::string stringify() const override final;

    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
