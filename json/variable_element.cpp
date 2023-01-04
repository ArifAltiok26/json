#include "variable_element.h"
#include "array.h"
#include "object.h"
namespace json
{

    VariableElement::VariableElement(DataPtr &data) : m_data(data) {}

    VariableElement &VariableElement::operator=(DataPtr data)
    {
        m_data = data;
        return *this;
    }

    VariableElement VariableElement::at(size_t index)
    {
        auto array = std::dynamic_pointer_cast<Array>(m_data);
        if (!array)
        {
            m_data = std::make_shared<Array>();
            return at(index);
        }
        return array->at(index);
    }

    VariableElement VariableElement::at(const std::string &key)
    {
        auto object = std::dynamic_pointer_cast<Object>(m_data);
        if (!object)
        {
            m_data = std::make_shared<Object>();
            return at(key);
        }
        return object->at(key);
    }

    VariableElement VariableElement::operator[](size_t index)
    {
        return at(index);
    }

    VariableElement VariableElement::operator[](const std::string &key)
    {
        return at(key);
    }

    std::string VariableElement::stringify() const
    {
        return m_data->stringify();
    }
} // namespace json
