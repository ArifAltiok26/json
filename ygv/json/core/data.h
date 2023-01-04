#pragma once
#include "serializable.h"
#include <memory>
namespace ygv
{
    namespace json
    {
        struct Data : Serializable
        {
            virtual ~Data() = default;
            virtual std::string serialize() const = 0;
        };

        using DataPtr = std::shared_ptr<Data>;
    }
}