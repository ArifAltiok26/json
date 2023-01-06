#include <iostream>
#include "ygv/json/types/types.h"
#include "ygv/json/variable.h"
#include <stack>
namespace ygv
{
    namespace json
    {

        enum class TokenType
        {
            Unknown,
            Comma,
            Colon,
            Null,
            IntNumber,
            FloatNumber,
            String,
            Boolean,
            ArrayStarted,
            ArrayEnded,
            ObjectStarted,
            ObjectEnded
        };

        class Token
        {
        public:
            Token() : Token(TokenType::Unknown) {}

            Token(TokenType type) : m_type(type) {}

            Token(TokenType type, const std::string &content) : m_type(type), m_content(content) {}

            TokenType type() const
            {
                return m_type;
            }

            std::pair<TokenType, std::string> operator*() const
            {
                return {m_type, m_content};
            }

            std::string content() const
            {
                return m_content;
            }

        private:
            TokenType m_type;
            std::string m_content;
        };

        struct JsonParseError : std::runtime_error
        {
            using std::runtime_error::runtime_error;
        };

        class Tokenizer
        {
        public:
            std::vector<Token> tokenize(const std::string &content)
            {
                clear();
                std::stack<char> stack;

                for (int i = 0; i < content.size(); i++)
                {
                    char ch = content[i];

                    switch (ch)
                    {
                    case '{':
                        emplace(TokenType::ObjectStarted);
                        stack.push(ch);
                        break;
                    case '[':
                        emplace(TokenType::ArrayStarted);
                        stack.push(ch);
                        break;
                    case '}':
                    {
                        if (stack.top() == '{')
                        {
                            flush_and_emplace(TokenType::ObjectEnded);
                            stack.pop();
                        }
                        else
                        {
                            throw JsonParseError("The object ended literal was found but its started literal wasn't found.");
                        }
                    }
                    break;
                    case ']':
                    {
                        if (stack.top() == '[')
                        {
                            flush_and_emplace(TokenType::ArrayEnded);
                            stack.pop();
                        }
                        else
                        {
                            throw JsonParseError("The array ended literal was found but its started literal wasn't found.");
                        }
                    }
                    break;
                    case '"':
                    {
                        if (stack.top() == '"')
                        {
                            emplace(TokenType::String, literal);
                            literal.clear();
                            stack.pop();
                        }
                        else
                        {
                            flushLiteral();
                            stack.push(ch);
                        }
                    }
                    break;
                    case ':':
                        flush_and_emplace(TokenType::Colon);
                        break;
                    case ',':
                        flush_and_emplace(TokenType::Comma);
                        break;
                    default:
                        literal += ch;
                        break;
                    }
                }

                if (!stack.empty())
                    throw JsonParseError("Not all tokens could be consumed.");
                return tokens;
            }

        private:
            void flushLiteral()
            {
                if (!literal.empty())
                {
                    if (literal == "true" || literal == "false")
                    {
                        tokens.emplace_back(TokenType::Boolean, literal);
                    }
                    else if (literal == "Null")
                    {
                        tokens.emplace_back(TokenType::Null);
                    }
                    else
                    {
                        bool hasDot = false;
                        TokenType type = TokenType::IntNumber;
                        for (char ch : literal)
                        {
                            if (ch == '.' && !hasDot)
                            {
                                hasDot = true;
                                type = TokenType::FloatNumber;
                            }
                            else if (!isdigit(ch))
                            {
                                throw JsonParseError("Literal is not a digit");
                            }
                        }
                        tokens.emplace_back(type, literal);
                    }
                    literal.clear();
                }
            }

            void emplace(TokenType type)
            {
                tokens.emplace_back(type);
            }

            void emplace(TokenType type, const std::string &content)
            {
                tokens.emplace_back(type, content);
            }

            void flush_and_emplace(TokenType type)
            {
                flushLiteral();
                emplace(type);
            }

            void flush_and_emplace(TokenType type, const std::string &content)
            {
                flushLiteral();
                emplace(type, content);
            }

            void clear()
            {
                tokens.clear();
                literal.clear();
            }

        private:
            std::string literal;
            std::vector<Token> tokens;
        };

        class Parser
        {
        public:
            Parser(Tokenizer &tokenizer) : tokenizer(tokenizer) {}

            std::string ignoreSpecialCharacter(const std::string &content)
            {
                std::string retval;
                bool isInString = false;
                for (char ch : content)
                {
                    switch (ch)
                    {
                    case '\'':
                    case '"':
                        retval += '"';
                        isInString = !isInString;
                        break;
                    case ' ':
                    case '\t':
                    case '\n':
                    case '\r':
                        if (isInString)
                            retval += ch;
                        break;
                    default:
                        retval += ch;
                    }
                }
                return retval;
            }

            DataPtr convertJsonBasicType(const Token &token) const
            {
                Variable variable;
                switch (token.type())
                {
                case TokenType::Null:
                    variable = nullptr;
                    break;
                case TokenType::String:
                    variable = token.content();
                    break;
                case TokenType::IntNumber:
                    variable = std::stoi(token.content());
                    break;
                case TokenType::FloatNumber:
                    variable = std::stof(token.content());
                    break;
                case TokenType::Boolean:
                    variable = token.content() == "true" ? true : false;
                    break;
                }
                return to_json(variable);
            }

            DataPtr parse(const std::vector<Token> &tokens) const
            {
                std::vector<Token>::const_iterator iter = tokens.begin();
                Variable root;

                while (iter != tokens.end())
                {
                    switch (iter->type())
                    {
                    case TokenType::ArrayStarted:

                        break;
                    case TokenType::ArrayEnded:
                        break;
                    case TokenType::ObjectStarted:
                        break;
                    case TokenType::ObjectEnded:
                        break;
                    default:
                        root = convertJsonBasicType(*iter);
                    }
                    std::cout << static_cast<size_t>(iter->type()) << " -> " << iter->content() << std::endl;
                    iter++;
                }
                return to_json(root);
            }

            DataPtr parse(const std::string &raw_content)
            {
                std::string content = ignoreSpecialCharacter(raw_content);
                std::cout << content << std::endl;
                auto tokens = tokenizer.tokenize(content);
                return parse(tokens);
            }

        private:
            Tokenizer &tokenizer;
        };
    } // namespace json
} // namespace ygv
#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"

int main(int argc, char const *argv[])
{

    using namespace ygv::json;

    Tokenizer tokenizer;
    Parser parser(tokenizer);

    std::string raw_content = "{'test':123.5, 'hello':Null,'arr':[1,0],'str':'Hello World'}";
    Variable variable = parser.parse(raw_content);
    std::cout << variable << std::endl;

    return 0;
}