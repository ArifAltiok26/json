#include <iostream>
#include "ygv/json/variable.h"
#include "ygv/json/stringify.h"
#include "ygv/json/utils/from_json.h"
using namespace ygv::json;

struct Role_t
{
    std::string name;
    int pin;
};

DataPtr to_json(const Role_t &role)
{
    Variable variable;
    variable["name"] = role.name;
    variable["pin"] = role.pin;
    return to_json(variable);
}

bool from_json(const Variable &variable, Role_t &role)
{
    if (!from_json_key(variable, "name", role.name))
        return false;
    if (!from_json_key(variable, "pin", role.pin))
        return false;

    return true;
}

struct Button_t
{
    std::string name;
    int pin;
    bool state;
};

DataPtr to_json(const Button_t &button)
{
    Variable variable;
    variable["name"] = button.name;
    variable["pin"] = button.pin;
    variable["state"] = button.state;
    return to_json(variable);
}

bool from_json(const Variable &variable, Button_t &button)
{
    if (!from_json_key(variable, "name", button.name))
        return false;
    if (!from_json_key(variable, "pin", button.pin))
        return false;
    if (!from_json_key(variable, "state", button.state))
        return false;

    return true;
}

struct Action_t
{
    std::string name;
    Role_t role;
    Button_t button;
};

DataPtr to_json(const Action_t &action)
{
    Variable variable;
    variable["name"] = action.name;
    variable["button"] = action.button;
    variable["role"] = action.role;
    return to_json(variable);
}

bool from_json(const Variable &variable, Action_t &action)
{
    if (!from_json_key(variable, "name", action.name))
    {
        return false;
    }
    if (!from_json_key(variable, "button", action.button))
    {
        return false;
    }
    if (!from_json_key(variable, "role", action.role))
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    Role_t role{"role_1", 1};
    Button_t button{"button_1", 2};
    Action_t action{"action_1", role, button};
    Variable variable;
    variable = action;
    std::cout << variable << std::endl;

    Action_t other;
    if (from_json(variable, other))
    {

        std::cout << other.name << std::endl;
        std::cout << other.button.name << " " << other.button.pin << " " << std::boolalpha << other.button.state << std::noboolalpha << std::endl;
        std::cout << other.role.name << " " << other.role.pin << std::endl;
    }
    else
    {
        std::cout << "couldn't success from_json" << std::endl;
    }

    return 0;
}