#pragma once
#include "to_array.h"
#include "to_object.h"
namespace json
{
    template <typename DataType>
    void to_json(Array &array, const std::vector<DataType> &datas)
    {
        for (int i = 0; i < datas.size(); i++)
        {
            array[i] = to_object(datas[i]);
        }
    }

    DataPtr convert(const std::string &value);

    DataPtr convert(const char *value);

    DataPtr convert(int value);

    DataPtr convert(float value);

    DataPtr convert(double value);

    DataPtr convert(bool value);
}