#pragma once
#include <vector>
#include "token.h"
namespace ygv
{
    namespace json
    {
        class Tokenizer
        {
        public:
            std::vector<Token> tokenize(const std::string &content);

        private:
            void flushLiteral(std::vector<Token> &tokens);

        private:
            bool isInString;
            std::string literal;
        };
    } // namespace json
} // namespace ygv