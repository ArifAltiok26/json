#include <iostream>
#include <json/object.h>
#include <json/utils.h>
int main(int argc, char const *argv[])
{
    json::Object object;

    object["test"] = json::convert(false);
    std::cout << object << std::endl;

    return 0;
}