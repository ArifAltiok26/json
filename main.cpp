#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"
#include <iostream>

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
    ygv::json::Variable var;
    var = Foo_t{"Arif", 1};
    std::cout << var << std::endl;
    return 0;
}
