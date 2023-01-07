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
            void reset();
            void flushLiteral();

        private:
            bool isInString;
            std::vector<Token> tokens;
            std::string literal;
        };
    } // namespace json
} // namespace ygv