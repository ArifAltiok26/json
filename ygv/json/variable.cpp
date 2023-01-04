#include "variable.h"
namespace ygv
{
    namespace json
    {

        Variable::Variable() : Variable(to_json(nullptr)) {}

        Variable::Variable(const DataPtr &data) : m_data(data), m_indexer(m_data) {}

        Variable &Variable::operator=(DataPtr data)
        {
            m_indexer = data;
            return *this;
        }

        bool Variable::exists(const std::string &key) const
        {
            return m_indexer.exists(key);
        }

        IndexableVariable Variable::operator[](size_t index)
        {
            return m_indexer[index];
        }

        IndexableVariable Variable::operator[](const std::string &key)
        {
            return m_indexer[key];
        }

        const IndexableVariable Variable::operator[](size_t index) const
        {
            return m_indexer[index];
        }

        const IndexableVariable Variable::operator[](const std::string &key) const
        {
            return m_indexer[key];
        }

        std::string Variable::serialize() const
        {
            return m_indexer.serialize();
        }

        DataPtr to_json(const Variable &variable)
        {
            return variable.m_data;
        }

    }
}