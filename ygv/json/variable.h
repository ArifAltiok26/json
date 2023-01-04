#pragma once
#include "ygv/json/core/data.h"
#include "ygv/json/utils/indexable_variable.h"
namespace ygv
{
    namespace json
    {
        class Variable : public Serializable
        {
        public:
            Variable();

            Variable(const DataPtr &data);

            template <typename ValueType>
            Variable(const ValueType &value) : Variable()
            {
                *this = value;
            }

            Variable &operator=(DataPtr data);

            template <typename ValueType>
            Variable &operator=(ValueType value)
            {
                m_indexer = value;
                return *this;
            }

            bool exists(const std::string &key) const;

            IndexableVariable operator[](size_t index);
            IndexableVariable operator[](const std::string &key);

            const IndexableVariable operator[](size_t index) const;
            const IndexableVariable operator[](const std::string &key) const;

            std::string serialize() const;

        private:
            friend DataPtr to_json(const Variable &);

        private:
            DataPtr m_data;
            IndexableVariable m_indexer;
        };

        DataPtr to_json(const Variable &variable);
    }
}