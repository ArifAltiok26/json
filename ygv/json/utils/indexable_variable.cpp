#include "indexable_variable.h"
#include "ygv/json/types/array.h"
#include "ygv/json/types/object.h"
#include "ygv/json/types/null.h"
namespace ygv
{
    namespace json
    {

        static DataPtr NullObject = std::make_shared<Null>();

        IndexableVariable::IndexableVariable(DataPtr &data) : m_data(data) {}

        IndexableVariable &IndexableVariable::operator=(DataPtr data)
        {
            m_data = data;
            return *this;
        }

        IndexableVariable IndexableVariable::operator=(const IndexableVariable &other)
        {
            m_data = other.m_data;
            return *this;
        }

        bool IndexableVariable::exists(const std::string &key) const
        {
            auto object = std::dynamic_pointer_cast<Object>(m_data);
            return object ? object->exists(key) : false;
        }

        IndexableVariable IndexableVariable::operator[](size_t index)
        {
            auto array = std::dynamic_pointer_cast<Array>(m_data);
            if (!array)
            {
                m_data = std::make_shared<Array>();
                return this->operator[](index);
            }
            return array->operator[](index);
        }

        IndexableVariable IndexableVariable::operator[](const std::string &key)
        {
            auto object = std::dynamic_pointer_cast<Object>(m_data);
            if (!object)
            {
                m_data = std::make_shared<Object>();
                return this->operator[](key);
            }
            return object->operator[](key);
        }

        const IndexableVariable IndexableVariable::operator[](size_t index) const
        {
            auto array = std::dynamic_pointer_cast<Array>(m_data);
            if (!array)
                return NullObject;
            return array->operator[](index);
        }

        const IndexableVariable IndexableVariable::operator[](const std::string &key) const
        {
            auto object = std::dynamic_pointer_cast<Object>(m_data);
            if (!object)
                return NullObject;
            return object->operator[](key);
        }

        std::string IndexableVariable::serialize() const
        {
            return m_data->serialize();
        }

    } // namespace json

} // namespace ygv