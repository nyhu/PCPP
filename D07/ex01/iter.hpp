#ifndef __ITER__
#define __ITER__

#include <iostream>

template <typename T>
void increm(T &i)
{
    i++;
}

template <typename T, typename U>
void iter(T *arr, U const &len, void (*f)(T &))
{
    for (U i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T, typename U>
void test(T *arr, U const &len)
{
    std::cout << "orign array : " << std::endl;
    for (U i = 0; i < len; i++)
        std::cout << "index : " << i << " value : " << arr[i] << std::endl;
    iter(arr, len, increm<T>);
    std::cout << "modified array : " << std::endl;
    for (U i = 0; i < len; i++)
        std::cout << "index : " << i << " value : " << arr[i] << std::endl;
}

#endif