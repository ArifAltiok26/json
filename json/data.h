#pragma once
#include <string>
namespace json
{
    struct Data
    {
        virtual ~Data() = default;
        virtual std::string stringify() const = 0;
    };
} // namespace json
