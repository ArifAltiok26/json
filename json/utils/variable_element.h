#pragma once
#include "../types/data_fwd.h"
#include "../utils/to_json.h"
namespace json
{
    class VariableElement : public Data
    {
    public:
        VariableElement(DataPtr &data);

        VariableElement &operator=(DataPtr data);

        template <typename ValueType>
        VariableElement &operator=(ValueType value);

        VariableElement at(size_t index);

        VariableElement at(const std::string &key);

        VariableElement operator[](size_t index);

        VariableElement operator[](const std::string &key);

        std::string stringify() const;

    private:
        DataPtr &m_data;
    };

    template <typename ValueType>
    VariableElement &VariableElement::operator=(ValueType value)
    {
        return *this = to_json(value);
    }
} // namespace json
