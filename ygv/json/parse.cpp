#include "parse.h"
#include "json/parser/parser.h"
namespace ygv
{
    namespace json
    {
        static Parser parser;
        Variable parse(const std::string &content)
        {
            static Parser parser;
            return parser.parse(content);
        }
    } // namespace json
} // namespace ygv
