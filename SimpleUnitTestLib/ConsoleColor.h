#ifndef __CONSOLE_COLOR__
#define  __CONSOLE_COLOR__
#include <iostream>
#include <windows.h>

struct ConsoleColor
{
    struct ConsoleColor(WORD color) : wColor(color) {}
    WORD wColor;
};

#define RED_COLOR   ConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY)
#define GREEN_COLOR ConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define WHITE_COLOR ConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>& 
operator << (std::basic_ostream<_Elem, _Traits> &o, ConsoleColor &color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h != 0)
    {
        SetConsoleTextAttribute(h, color.wColor);
    }
    return o;
}

#endif // !__CONSOLE_COLOR__