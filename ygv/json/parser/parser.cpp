#include "parser.h"
#include "tokenizer.h"
#include "ygv/json/types/types.h"
#include <stack>
#include "pair.h"

#include <iostream>
namespace ygv
{
    namespace json
    {

        Variable Parser::parse(const std::string &raw_content)
        {
            Tokenizer tokenizer;
            std::string content = ignoreSpecialCharacter(raw_content);
            auto tokens = tokenizer.tokenize(content);
            std::stack<TokenType> operators;
            std::stack<DataPtr> operands;

            for (auto iter = tokens.rbegin(); iter != tokens.rend(); iter++)
            {
                auto [type, content] = **iter;
                switch (type)
                {
                case TokenType::Object_Ended:
                case TokenType::Array_Ended:
                    operators.push(type);
                    break;

                case TokenType::Array_Started:
                {
                    std::shared_ptr<Array> data = std::make_shared<Array>();
                    Array &array = *data;
                    int counter = 0;
                    while (operators.top() != TokenType::Array_Ended)
                    {
                        if (!operands.empty())
                        {
                            array[counter++] = operands.top();
                            operands.pop();
                        }
                        operators.pop();
                    }
                    operands.push(data);
                }
                break;
                case TokenType::Object_Started:
                {

                    std::shared_ptr<Object> data = std::make_shared<Object>();
                    Object &object = *data;
                    while (operators.top() != TokenType::Object_Ended)
                    {
                        if (!operands.empty())
                        {
                            auto pair = std::dynamic_pointer_cast<Pair>(operands.top());
                            if (!pair)
                            {
                                throw "123";
                            }
                            object[pair->key()] = pair->value();
                            operands.pop();
                        }
                        operators.pop();
                    }
                    operands.push(data);
                }
                break;
                case TokenType::Colon:
                {
                    DataPtr data = operands.top();
                    Token key = *(iter + 1);
                    if (key.type() == TokenType::String)
                    {
                        operands.pop();
                        iter++;
                        operands.push(std::make_shared<Pair>(key.content(), data));
                        operators.push(TokenType::Comma);
                    }
                    else
                    {
                        throw "123";
                    }
                }
                break;

                case TokenType::String:
                    operands.push(std::make_shared<String>(content));
                    operators.push(TokenType::Comma);
                    break;
                case TokenType::IntNumber:
                    operands.push(std::make_shared<IntNumber>(std::stoi(content)));
                    operators.push(TokenType::Comma);
                    break;
                case TokenType::FloatNumber:
                    operands.push(std::make_shared<FloatNumber>(std::stof(content)));
                    operators.push(TokenType::Comma);
                    break;
                case TokenType::Boolean:
                    operands.push(std::make_shared<Boolean>(content == "true" ? true : false));
                    operators.push(TokenType::Comma);
                    break;
                case TokenType::Null:
                    operands.push(std::make_shared<Null>());
                    operators.push(TokenType::Comma);
                    break;
                }
            }

            struct JsonParseError : public std::runtime_error
            {
                using std::runtime_error::runtime_error;
            };

            Variable retval;
            if (operands.size() > 1)
            {
                throw JsonParseError("After parsing Operand size must be 1");
            }
            else if (!operands.empty())
            {
                DataPtr data = operands.top();
                if (std::dynamic_pointer_cast<Pair>(data))
                {
                    throw JsonParseError("After parsing root element must not be a pair. It should be an object ?");
                }
                retval = data;
            }

            return retval;
        }

        std::string Parser::ignoreSpecialCharacter(const std::string &content) const
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

    } // namespace json

} // namespace ygv
