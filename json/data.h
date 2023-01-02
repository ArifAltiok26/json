#pragma once
#include <string>
#include <memory>
namespace json
{
    struct Data
    {
        virtual ~Data() = default;
        virtual std::string stringify() const = 0;
    };

    using DataPtr = std::shared_ptr<Data>;
    using DataUPtr = std::unique_ptr<Data>;
} // namespace json
