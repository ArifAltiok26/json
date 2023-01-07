#include "token.h"

namespace ygv
{
    namespace json
    {

        Token::Token(TokenType type) : m_type(type) {}
        Token::Token(TokenType type, const std::string &content) : m_type(type), m_content(content) {}

        TokenType Token::type() const
        {
            return m_type;
        }
        std::string Token::content() const
        {
            return m_content;
        }
        std::pair<TokenType, std::string> Token::operator*() const
        {
            return {m_type, m_content};
        }

    } // namespace json
} // namespace ygv