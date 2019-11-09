#include "Screen.h"
#include <iostream>

Screen &Screen::mov(int cur)
{
    cursor = cur;
    return *this;
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

const Screen &Screen::display() const
{
    std::cout<<contents[cursor];
    return *this;
}
