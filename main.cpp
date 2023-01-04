
#include <iostream>
#include "json/utils.h"
#include "json/to_json.h"
using namespace json;

struct Foo
{
    std::string name;
    int value;
};

void to_object(json::Object &object, const Foo &foo)
{
    object["name"] = json::to_json(foo.name);
    object["value"] = json::to_json(foo.value);
}
#include "json/variable.h"

struct Camera_t
{
    std::string name;
    std::string ip;
    int port;
};

void to_object(json::Object &object, const Camera_t &camera)
{
    object["name"] = to_json(camera.name);
    object["ip"] = to_json(camera.ip);
    object["port"] = to_json(camera.port);
}

struct Button_t
{
    std::string name;
    int pin;
};

void to_object(json::Object &object, const Button_t &button)
{
    object["name"] = to_json(button.name);
    object["pin"] = to_json(button.pin);
}

int main(int argc, char const *argv[])
{

    json::Variable variable;

    variable["cameras"] = to_json<Camera_t>({{"camera_1", "192.168.1.8", 50000}, {"camera_2", "192.168.1.9", 50002}});
    variable["buttons"] = to_json<Button_t>({{"btn_1", 1}, {"btn_2", 2}, {"btn_3", 4}, {"btn_4", 3}});

    std::cout << variable.stringify() << std::endl;
    return 0;
}
