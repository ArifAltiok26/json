#pragma once
#include "../types/object.h"
namespace json
{
    template <typename DataType>
    DataPtr to_object(const DataType &data)
    {
        std::shared_ptr<Object> retval = std::make_shared<Object>();
        to_json(*retval, data);
        return retval;
    }

} // namespace json
