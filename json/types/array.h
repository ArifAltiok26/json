#pragma once
#include "data.h"
#include "data_fwd.h"
namespace json
{
    class Array : public Data
    {
    public:
        Array();

        ~Array();

        DataPtr &operator[](size_t index);

        std::string stringify() const override final;

        size_t size() const;

    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
