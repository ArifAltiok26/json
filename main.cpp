#include <iostream>
#include "ygv/json/types/array.h"
#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"
#include "ygv/json/version.h"
#include "ygv/version.h"
struct Foo_t
{
    std::string name;
    int value;
};

ygv::json::DataPtr to_json(const Foo_t &foo)
{
    ygv::json::Variable variable;
    variable["name"] = foo.name;
    variable["value"] = foo.value;
    return to_json(variable);
}

int main(int argc, char const *argv[])
{
    std::cout << ygv::version() << std::endl;
    std::cout << ygv::json::version() << std::endl;

    ygv::json::Variable var;
    var = std::vector<Foo_t>{{"Test_1", 1}, {"Test_2", 2}};
    std::cout << var << std::endl;
    return 0;
}
