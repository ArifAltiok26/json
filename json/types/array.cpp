#include "array.h"
#include "null.h"
namespace json
{

    using Container = Array::Container;

    std::string Array::stringify() const
    {
        std::string retval;
        if (!m_container.empty())
        {
            Container::const_iterator iter = m_container.begin();
            retval += (*iter)->stringify();
            while (++iter != m_container.end())
            {
                retval += ", " + (*iter)->stringify();
            }
        }
        return "[" + retval + "]";
    }

    DataPtr &Array::at(size_t index)
    {
        size_t oldSize = size();
        if (index >= oldSize)
        {
            m_container.resize(index + 1);
            std::fill(m_container.begin() + oldSize, m_container.end(), std::make_shared<Null>());
        }
        return m_container[index];
    }

    DataPtr &Array::operator[](size_t index)
    {
        return at(index);
    }

    size_t Array::size() const
    {
        return m_container.size();
    }

    Container::iterator Array::begin()
    {
        return m_container.begin();
    }

    Container::iterator Array::end()
    {
        return m_container.end();
    }

    Container::const_iterator Array::begin() const
    {
        return m_container.cbegin();
    }

    Container::const_iterator Array::end() const
    {
        return m_container.cend();
    }

} // namespace json
