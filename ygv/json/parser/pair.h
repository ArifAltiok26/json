#include "ygv/json/core/data.h"
namespace ygv
{
    namespace json
    {

        class Pair : public Data
        {

        public:
            Pair(const std::string &key);

            Pair(const std::string &key, DataPtr value);

            Pair &operator=(DataPtr value);

            std::string serialize() const;

            std::string key() const;

            DataPtr &value();

            const DataPtr value() const;

            bool operator==(const Pair &pair) const;

        private:
            std::string m_key;
            DataPtr m_value;
        };

    } // namespace json

} // namespace ygv
