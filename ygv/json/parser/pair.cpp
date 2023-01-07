#include "pair.h"
#include "ygv/json/types/null.h"
namespace ygv
{
    namespace json
    {

        Pair::Pair(const std::string &key) : Pair(key, std::make_shared<Null>())
        {
        }

        Pair::Pair(const std::string &key, DataPtr value) : m_key(key), m_value(value) {}

        Pair &Pair::operator=(DataPtr value)
        {
            m_value = value;
            return *this;
        }

        std::string Pair::serialize() const
        {
            return "\"" + m_key + "\":" + m_value->serialize();
        }

        std::string Pair::key() const
        {
            return m_key;
        }

        DataPtr &Pair::value()
        {
            return m_value;
        }

        const DataPtr Pair::value() const
        {
            return m_value;
        }

        bool Pair::operator==(const Pair &pair) const
        {
            return m_key == pair.m_key;
        }

    } // namespace json

} // namespace ygv
