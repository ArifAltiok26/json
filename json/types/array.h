#pragma once
#include "data.h"
#include "data_fwd.h"
#include <vector>

#include <vector>
namespace json
{

    class Array : public Data
    {

    public:
        using Container = std::vector<DataPtr>;

        std::string stringify() const;

        DataPtr &at(size_t index);

        DataPtr &operator[](size_t index);

        size_t size() const;

        Container::const_iterator begin() const;

        Container::const_iterator end() const;

        Container::iterator begin();

        Container::iterator end();

    private:
        Container m_container;
    };

} // namespace json
