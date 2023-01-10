
#include <iostream>
#include "ygv/json/json.h"
#include <sstream>
int main(int argc, char const *argv[])
{

    using namespace ygv::json;

    std::string raw_content = "{'a':1,'b':[1,2,3],'c':'d','e':{'f':'ghost','h':[5,6]},'z':{'state':true,'dummy':false}}";
    // std::string raw_content = "'{name':123}";
    // std::string raw_content = "123";
    // std::string raw_content = "true";
    // std::string raw_content = "false";

    std::stringstream iss;
    iss << "{";
    iss << "'value':123"
        << ",";
    iss << "\"name\":\"dummy\""
        << ",";
    iss << "'state':" << std::boolalpha << true;
    iss << ","
        << "'nested':{'value':321}";
    iss << ","
        << "'nested_other':{'value':111}";
    iss << "}";
    Variable variable = parse(iss);
    std::cout << variable << std::endl;

    return 0;
}