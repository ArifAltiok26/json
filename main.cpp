

#include "json/convert/convert.h"
#include "json/types/utils.h"

struct Button
{
    uint8_t pin;
    bool state;
};

void to_json(json::Object &object, const Button &button)
{
    object["pin"] = json::convert(button.pin);
    object["state"] = json::convert(button.state);
}

struct Action
{
    std::string name;
    Button button;
    uint8_t role;
    std::string ip;
    bool isActive;
};

void to_json(json::Object &object, const Action &action)
{
    object["name"] = json::convert(action.name);
    object["button"] = json::to_object(action.button);
    object["role"] = json::convert(action.role);
    object["ip"] = json::convert(action.ip);
    object["isActive"] = json::convert(action.isActive);
}

bool from_json(const json::Object &object, Action &action)
{
}

int main(int argc, char const *argv[])
{
    Action actions = {"Salon", {1, true}, 2, "192.168.1.8", false};
    auto retval = json::to_object(actions);
    std::cout << *retval << std::endl;

    return 0;
}
