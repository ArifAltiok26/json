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

        Variable parse(std::istream &input)
        {
            std::string content;
            std::string line;
            while (std::getline(input, line))
                content += line;
            return parse(content);
        }
    } // namespace json
} // namespace ygv
