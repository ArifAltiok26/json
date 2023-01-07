#pragma once
#include "ygv/json/variable.h"
namespace ygv
{
    namespace json
    {

        class Parser
        {
        public:
            Variable parse(const std::string &raw_content);

        private:
            std::string ignoreSpecialCharacter(const std::string &content) const;
        };
    } // namespace json

} // namespace ygv
