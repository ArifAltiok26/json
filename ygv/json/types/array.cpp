#include "array.h"
#include "null.h"
namespace ygv
{
    namespace json
    {

        using Container = Array::Container;

        Container::value_type &Array::operator[](size_t index)
        {
            std::size_t currentSize = m_elements.size();
            if (index >= currentSize)
            {
                m_elements.resize(index + 1);
                std::fill(m_elements.begin() + currentSize, m_elements.end(), std::make_shared<Null>());
            }
            return m_elements[index];
        }

        const Container::value_type Array::operator[](size_t index) const
        {
            static DataPtr NullObject = std::shared_ptr<Null>();
            return index < m_elements.size() ? m_elements[index] : NullObject;
        }

        std::string Array::serialize() const
        {
            std::string retval;
            if (!m_elements.empty())
            {
                auto iter = m_elements.begin();
                retval += (*iter)->serialize();
                while (++iter != m_elements.end())
                {
                    retval += ", " + (*iter)->serialize();
                }
            }
            return "[" + retval + "]";
        }

        //////////////////////////////

        DataPtr to_json(Array &&array)
        {
            return std::shared_ptr<Array>(new Array(std::move(array)));
        }

        DataPtr to_json(Array array)
        {
            return std::shared_ptr<Array>(new Array(array));
        }

    } // namespace json

} // namespace ygv
