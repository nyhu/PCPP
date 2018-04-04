#include "whatever.hpp"

template <typename T>
void swap(T &x, T &y)
{
    T mem = x;
    x = y;
    y = mem;
}

template <typename T>
T const &min(T const &x, T const &y)
{
    return x < y ? x : y;
}

template <typename T>
T const &max(T const &x, T const &y)
{
    return x > y ? x : y;
}
