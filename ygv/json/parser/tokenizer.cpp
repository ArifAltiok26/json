#include "tokenizer.h"
namespace ygv
{
    namespace json
    {
        std::vector<Token> Tokenizer::tokenize(const std::string &content)
        {
            literal.clear();
            isInString = false;
            std::vector<Token> tokens;
            for (const auto ch : content)
            {
                switch (ch)
                {
                case '{':
                    tokens.emplace_back(TokenType::Object_Started);
                    break;
                case '[':
                    tokens.emplace_back(TokenType::Array_Started);
                    break;
                case '}':
                    flushLiteral(tokens);
                    tokens.emplace_back(TokenType::Object_Ended);
                    break;
                case ']':
                    flushLiteral(tokens);
                    tokens.emplace_back(TokenType::Array_Ended);
                    break;
                case ',':
                    flushLiteral(tokens);
                    tokens.emplace_back(TokenType::Comma);
                    break;
                case '"':
                    isInString = true;
                    flushLiteral(tokens);
                    isInString = false;
                    break;
                case ':':
                    flushLiteral(tokens);
                    tokens.emplace_back(TokenType::Colon);
                    break;
                default:
                    literal += ch;
                }
            }
            flushLiteral(tokens);
            return std::move(tokens);
        }

        void Tokenizer::flushLiteral(std::vector<Token> &tokens)
        {
            if (!literal.empty())
            {

                if (literal == "Null")
                {
                    tokens.emplace_back(TokenType::Null);
                }
                else if (literal == "true" || literal == "false")
                {
                    tokens.emplace_back(TokenType::Boolean, literal);
                }
                else
                {
                    if (isInString)
                    {
                        tokens.emplace_back(TokenType::String, literal);
                    }
                    else
                    {
                        TokenType type = TokenType::IntNumber;
                        for (char ch : literal)
                        {
                            if (std::isdigit(ch))
                            {
                            }
                            else if (ch == '.' && type == TokenType::IntNumber)
                            {
                                type = TokenType::FloatNumber;
                            }
                            else
                            {
                                throw "Error";
                            }
                        }
                        tokens.emplace_back(type, literal);
                    }
                }
                literal.clear();
            }
        }

    } // namespace json
} // namespace ygv