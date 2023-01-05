#include <iostream>
#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"
#include "put_line.h"

int main(int argc, char const *argv[])
{

    using namespace ygv::json;

    // The Variable class can hold with in itself.
    Variable variable;

    Variable other;
    other["name"] = "something";
    other["value"] = 123;
    other["state"] = true;

    variable["other_variable"] = other;
    std::cout << other << std::endl;
    put_line();
    std::cout << variable << std::endl;
    put_line();
    return 0;
}
