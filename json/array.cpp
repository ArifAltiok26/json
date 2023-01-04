#include "array.h"
#include <vector>
#include "null.h"
namespace json
{

    class Array::Impl
    {
        using Container = std::vector<DataPtr>;

    public:
        std::string stringify() const
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

        DataPtr &at(size_t index)
        {
            size_t oldSize = size();
            if (index >= oldSize)
            {
                m_container.resize(index + 1);
                std::fill(m_container.begin() + oldSize, m_container.end(), std::make_shared<Null>());
            }
            return m_container[index];
        }

        size_t size() const
        {
            return m_container.size();
        }

    private:
        Container m_container;
    };

    Array::Array()
    {
        impl = new Impl;
    }

    Array::~Array()
    {
        delete impl;
    }

    DataPtr &Array::at(size_t index)
    {
        return impl->at(index);
    }

    DataPtr &Array::operator[](size_t index)
    {
        return at(index);
    }

    std::string Array::stringify() const
    {
        return impl->stringify();
    }

    size_t Array::size() const
    {
        return impl->size();
    }

} // namespace json
