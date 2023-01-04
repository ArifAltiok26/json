#include "number.h"
#include "data_fwd.h"
namespace json
{
    template <typename ValueType>
    class TNumber : public Data
    {
    public:
        TNumber() = default;
        TNumber(ValueType value) : m_value(value)
        {
        }

        std::string stringify() const override final
        {
            return std::to_string(m_value);
        }

        ValueType value() const
        {
            return m_value;
        }

    private:
        ValueType m_value;
    };

    using IntNumber = TNumber<int>;
    using FloatNumber = TNumber<float>;
    using DoubleNumber = TNumber<double>;

    class Number::Impl
    {
    public:
        Impl &operator=(DataPtr data)
        {
            m_data = data;
            return *this;
        }

        std::string stringify() const
        {
            return m_data ? m_data->stringify() : "";
        }

    private:
        DataPtr m_data;
    };

    Number::Number()
    {
        impl = new Impl;
    }

    Number::~Number()
    {
        delete impl;
    }

    Number &Number::operator=(int value)
    {
        (*impl) = std::make_shared<IntNumber>(value);
        return *this;
    }

    Number &Number::operator=(long value)
    {
        (*impl) = std::make_shared<IntNumber>(value);
        return *this;
    }

    Number &Number::operator=(float value)
    {
        (*impl) = std::make_shared<FloatNumber>(value);
        return *this;
    }

    Number &Number::operator=(double value)
    {
        (*impl) = std::make_shared<FloatNumber>(value);
        return *this;
    }

    std::string Number::stringify() const
    {
        return impl->stringify();
    }
} // namespace json
