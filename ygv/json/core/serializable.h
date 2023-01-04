#pragma once
#include <string>
namespace ygv
{
    namespace json
    {
        struct Serializable
        {
            virtual ~Serializable() = default;
            virtual std::string serialize() const = 0;
        };
    }
}