#include <memory>
namespace json
{
    class Data;
    using DataPtr = std::shared_ptr<Data>;
    using DataUPtr = std::unique_ptr<Data>;
}