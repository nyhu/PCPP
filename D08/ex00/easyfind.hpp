#ifndef __EASY_FIND__
#define __EASY_FIND__

#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>


template<typename T>
int easyfind(T &container, int needle) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), needle);
    if (it != container.end())
        return *it;
    else
        throw std::logic_error("Value doesn't exist in the container.");
}

#endif