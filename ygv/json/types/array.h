#pragma once
#include <vector>
#include "ygv/json/core/data.h"
#include "ygv/json/utils/to_json.h"
namespace ygv
{
    namespace json
    {
        class Array : public Data
        {
        public:
            using Container = std::vector<DataPtr>;

            Container::value_type &operator[](size_t index);

            const Container::value_type operator[](size_t index) const;

            std::string serialize() const override final;

        private:
            Container m_elements;
        };

        //////////////////////////////

        DataPtr to_json(Array &&array);

        DataPtr to_json(Array array);

        template <typename ValueType>
        DataPtr to_json(const std::vector<ValueType> &values)
        {
            auto retval = std::make_shared<Array>();
            Array &array = *retval;
            for (int i = 0; i < values.size(); i++)
            {
                array[i] = to_json(values[i]);
            }
            return retval;
        }

    } // namespace json

} // namespace ygv
