#pragma once
#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {
        class Null : public Data
        {
        public:
            std::string serialize() const override final
            {
                return "Null";
            }
        };
    }
}