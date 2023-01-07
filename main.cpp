
#include <iostream>
#include "ygv/json/json.h"
int main(int argc, char const *argv[])
{

    using namespace ygv::json;

    std::string raw_content = "{'a':1,'b':[1,2,3],'c':'d','e':{'f':'ghost','h':[5,6]},'z':{'state':true,'dummy':false}}";
    // std::string raw_content = "'{name':123}";
    // std::string raw_content = "123";
    // std::string raw_content = "true";
    // std::string raw_content = "false";

    Variable variable = parse(raw_content);
    std::cout << variable << std::endl;

    return 0;
}