#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <stdexcept>
#include <cstring>

template <typename T>
class Array
{
    T *_array;
    size_t _size;

  public:
    Array(void) : _array(NULL), _size(0) {}

    Array(unsigned int n) : _array(new T[n]), _size(n)
    {
        std::memset(_array, 0, _size * sizeof(T));
    }

    Array(Array const &src)
    {
        *this = src;
    }

    virtual ~Array()
    {
        if (_size != 0)
            delete[] _array;
    }

    Array &operator=(Array const &rhs)
    {
        if (_size != 0)
            delete _array;

        _size = rhs.size();
        _array = new T[_size];

        for (size_t i = 0; i < _size; i++)
            _array[i] = rhs[i];
        return *this;
    }


    size_t size(void) const
    {
        return _size;
    }

    T &operator[](size_t index) const
    {
        if (_size <= index)
            throw std::exception();
        return _array[index];
    }
};

#endif