#pragma once
#include "utils/variable_element.h"
namespace json
{

    class Variable : public Data
    {
    public:
        Variable();

        Variable &operator=(DataPtr data);

        template <typename ValueType>
        Variable &operator=(ValueType value);

        std::string stringify() const;

        VariableElement operator[](size_t index);

        VariableElement operator[](const std::string &key);

        template <typename Variable>
        friend DataPtr to_json(Variable variable);

    private:
        json::DataPtr m_data;
        VariableElement m_element;
    };

    template <typename ValueType>
    Variable &Variable::operator=(ValueType value)
    {
        return *this = to_json(value);
    }

} // namespace json