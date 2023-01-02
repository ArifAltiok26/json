#pragma once
#include "data.h"
#include "data_fwd.h"
#include <vector>
namespace json
{
    class Object : public Data
    {
    public:
        Object();

        ~Object();

        DataPtr &operator[](const std::string &key);

        std::string stringify() const override final;

        std::vector<std::string> keys() const;

        bool exists(const std::string &key) const;

    private:
        class Impl;
        Impl *impl;
    };
} // namespace json
