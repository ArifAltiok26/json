#pragma once
#include "token_type.h"
#include <utility>
#include <string>
namespace ygv
{
    namespace json
    {

        class Token
        {
        public:
            Token(TokenType type);
            Token(TokenType type, const std::string &content);

            TokenType type() const;
            std::string content() const;
            std::pair<TokenType, std::string> operator*() const;

        private:
            TokenType m_type;
            std::string m_content;
        };

    } // namespace json
} // namespace ygv