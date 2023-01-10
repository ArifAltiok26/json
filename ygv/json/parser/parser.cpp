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

        struct JsonParseError : public std::runtime_error
        {
            using std::runtime_error::runtime_error;
        };

        Variable Parser::parse(const std::string &raw_content)
        {
            static Tokenizer tokenizer;
            std::string content = ignoreSpecialCharacter(raw_content);
            auto tokens = tokenizer.tokenize(content);
            std::stack<TokenType> operators;
            std::stack<DataPtr> operands;

            auto pushNewOperand = [&operators, &operands](DataPtr data)
            {
                operands.push(data);
                operators.push(TokenType::Comma);
            };

            auto popOperand = [&operators, &operands]
            {
                auto data = operands.top();
                operands.pop();
                operators.pop();
                return data;
            };

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
                    std::shared_ptr<Array> array = std::make_shared<Array>();
                    Array &arrRef = *array;
                    int counter = 0;
                    while (operators.top() == TokenType::Comma)
                    {
                        arrRef[counter++] = popOperand();
                    }
                    operators.pop();
                    pushNewOperand(array);
                }
                break;
                case TokenType::Object_Started:
                {
                    std::stack<std::shared_ptr<Pair>> pairs;
                    while (operators.top() == TokenType::Comma)
                    {
                        if (auto pair = std::dynamic_pointer_cast<Pair>(popOperand()))
                            pairs.push(std::move(pair));
                        else
                            throw JsonParseError("Object started literal was found but previous operand not a pair");
                    }

                    operators.pop();

                    std::shared_ptr<Object> object = std::make_shared<Object>();
                    Object &objectRef = *object;
                    while (!pairs.empty())
                    {
                        auto pair = pairs.top();
                        pairs.pop();
                        objectRef[pair->key()] = pair->value();
                    }

                    pushNewOperand(object);
                }
                break;
                case TokenType::Colon:
                {
                    Token key = *(++iter);
                    if (key.type() == TokenType::String)
                    {
                        DataPtr data = popOperand();
                        pushNewOperand(std::make_shared<Pair>(key.content(), data));
                    }
                    else
                    {
                        throw JsonParseError("Colon literal was found but previous operand not a pair");
                    }
                }
                break;

                case TokenType::String:
                    pushNewOperand(std::make_shared<String>(content));
                    break;
                case TokenType::IntNumber:
                    pushNewOperand(std::make_shared<IntNumber>(std::stoi(content)));
                    break;
                case TokenType::FloatNumber:
                    pushNewOperand(std::make_shared<FloatNumber>(std::stof(content)));
                    break;
                case TokenType::Boolean:
                    pushNewOperand(std::make_shared<Boolean>(content == "true" ? true : false));
                    break;
                case TokenType::Null:
                    pushNewOperand(std::make_shared<Null>());
                    break;
                }
            }

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
