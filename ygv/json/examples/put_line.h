#pragma once
#include <iostream>
void put_line(size_t size = 25)
{
    std::string line;
    line.resize(25, '*');
    std::cout << line << std::endl;
}