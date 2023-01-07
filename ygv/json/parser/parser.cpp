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

                            if (auto pair = std::dynamic_pointer_cast<Pair>(operands.top()))
                            {
                                object[pair->key()] = pair->value();
                                operands.pop();
                            }
                            else
                            {
                                throw JsonParseError("Object started literal was found but previous operand not a pair");
                            }
                        }
                        operators.pop();
                    }
                    operands.push(data);
                }
                break;
                case TokenType::Colon:
                {
                    Token key = *(iter + 1);
                    if (key.type() == TokenType::String)
                    {
                        DataPtr data = operands.top();
                        operands.pop();
                        pushNewOperand(std::make_shared<Pair>(key.content(), data));
                        iter++;
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
