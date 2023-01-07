#pragma once
namespace ygv
{
    namespace json
    {
        enum class TokenType
        {

            Colon,
            Comma,
            Array_Started,
            Array_Ended,
            Object_Started,
            Object_Ended,
            String,
            IntNumber,
            FloatNumber,
            Boolean,
            Null,
        };
    } // namespace json

} // namespace ygv
