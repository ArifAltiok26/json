#include <iostream>
#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"

#include "put_line.h"

int main(int argc, char const *argv[])
{
    using namespace ygv::json;
    // First of all, our prime type is Variable Class.

    //  It has lots of advance behavior which you can see following lines.

    Variable variable;

    // It will start with null object if you dont assign any value.

    // Of course, you can print it into any stream object.

    // You should include "ygv/json/stringify.h" header if you want print it.

    // And then use just like following line.

    std::cout << "You should see output Null" << std::endl;

    std::cout << variable << std::endl;

    // Or you can use another one.

    std::cout << "You should see same result like before" << std::endl;
    std::cout << stringify(variable) << std::endl;

    // This function just an utils to seperate amoung two outs of console. It doesn't matter. :)

    put_line();

    //********************************************//

    // Let's look at behavior of Variable Class.

    // The Variable class can automatically infer the type of the value
    // It means you can assing directly any built in value type.
    // Of course, you can assing user-defined types. But we will see later.

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

    // Important thing here is Variable Class will delete automatically previous type if you assign other type.
    // e.g
    //      assume that variable class holds any object. And then we assigned it any array object.
    //      Thus variable instance's type will be changed automatically array type and it's previous type will be destroyed.
    //      This is to prevent the memory leak. I think that it is usefull behavior.

    // Let's look at examples.

    // now the variable holds type of integer
    variable = 123;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of float
    variable = 123.52f;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of float.
    // Accually, type of our value was double.
    // But we converted it to float.

    variable = 123.52;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of string
    variable = "123";
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of boolean
    variable = true;
    std::cout << variable << std::endl;
    variable = false;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of null
    variable = nullptr;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of array
    variable[0] = 123;
    variable[1] = 123.52;
    variable[2] = "123";
    variable[3] = true;
    variable[4] = false;
    variable[5] = nullptr;
    std::cout << variable << std::endl;
    put_line();

    // now the variable holds type of object
    variable["number_i"] = 123;
    variable["number_f"] = 123.52;
    variable["text"] = "123";
    variable["bool_t"] = true;
    variable["bool_f"] = false;
    variable["null_object"] = nullptr;
    std::cout << variable << std::endl;
    put_line();

    return 0;
}