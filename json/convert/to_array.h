#pragma once
#include "../types/array.h"
namespace json
{
    template <typename DataType>
    DataPtr to_array(const DataType &data)
    {
        std::shared_ptr<Array> retval = std::make_shared<Array>();
        to_json(*retval, data);
        return retval;
    }
} // namespace  json
