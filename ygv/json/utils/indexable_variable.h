#pragma once
#include "to_json.h"
namespace ygv
{
    namespace json
    {

        class IndexableVariable : public Serializable
        {
        public:
            IndexableVariable(DataPtr &data);

            IndexableVariable &operator=(DataPtr data);

            IndexableVariable operator=(const IndexableVariable &other);

            template <typename ValueType>
            IndexableVariable &operator=(ValueType value)
            {
                return *this = to_json(value);
            }

            bool exists(const std::string &key) const;

            IndexableVariable operator[](size_t index);

            IndexableVariable operator[](const std::string &key);

            const IndexableVariable operator[](size_t index) const;

            const IndexableVariable operator[](const std::string &key) const;

            std::string serialize() const override final;

            const DataPtr operator*() const
            {
                return m_data;
            }

        private:
            DataPtr &m_data;
        };

    } // namespace json

} // namespace ygv