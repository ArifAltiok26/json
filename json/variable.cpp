#include "variable.h"
#include "utils/to_json.h"
namespace json
{

    Variable::Variable() : m_data(to_json(nullptr)), m_element(m_data)
    {
    }

    Variable &Variable::operator=(DataPtr data)
    {
        m_element = data;
        return *this;
    }

    std::string Variable::stringify() const
    {
        return m_element.stringify();
    }

    VariableElement Variable::operator[](size_t index)
    {
        return m_element[index];
    }

    VariableElement Variable::operator[](const std::string &key)
    {
        return m_element[key];
    }
} // namespace json