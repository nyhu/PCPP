#include "Span.hpp"

Span::Span() {
    _container.reserve(0);
}
Span::Span(Span const &s)
{
    *this = s;
}
Span::Span(unsigned int n)
{
    _container.reserve(n);
}

Span &Span::operator=(Span const &s)
{
    _container = s._container;
    return *this;
}

void Span::addNumber(int i)
{
    if (_container.size() >= _container.capacity())
        throw std::logic_error("span already full");
    _container.push_back(i);
}

int Span::longestSpan()
{
    if (_container.size() < 2)
        throw std::logic_error("span does not contain enough element for longest span");

    int result = std::abs(_container[0] - _container[1]);
    for (unsigned int i = 2; i < _container.size(); ++i)
        if (std::abs(_container[i] - _container[i - 1]) > result)
            result = std::abs(_container[i] - _container[i - 1]);

    return result;
}

int Span::shortestSpan()
{
    if (_container.size() < 2)
        throw std::logic_error("span does not contain enough element for shortest span");

    int result = std::abs(_container[0] - _container[1]);
    for (unsigned int i = 2; i < _container.size(); ++i)
        if (std::abs(_container[i] - _container[i - 1]) < result)
            result = std::abs(_container[i] - _container[i - 1]);

    return result;
}

Span::~Span() {}
