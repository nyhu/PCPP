#include "Span.hpp"

Span::Span() {}
Span::Span(Span const &s)
{
    *this = s;
}
Span::Span(unsigned int n)
{
    _container.assign(n, 0);
    _it = _container.begin();
}
Span &Span::operator=(Span const &s)
{
    _container = s._container;
    _it = s._it;
    return *this;
}

void Span::addNumber(int i)
{
    if (_it == _container.end())
        throw std::logic_error("span already full");
    *_it = i;
    _it++;
}

int Span::longestSpan()
{
    std::vector<int>::iterator begin = _container.begin();
    if (_it == begin || _it == begin + 1)
        throw std::logic_error("span does not contain enough element for longest span");

    int result = std::abs(*begin - *(begin + 1));
    for (; begin < _it; ++begin)
        if (std::abs(*begin - *(begin - 1)) > result)
            result = std::abs(*begin - *(begin - 1));

    return result;
}

int Span::shortestSpan()
{
    std::vector<int>::iterator begin = _container.begin();
    if (_it == begin || _it == begin + 1)
        throw std::logic_error("span does not contain enough element for shortest span");

    int result = std::abs(*begin - *(begin + 1));
    for (; begin < _it; ++begin)
        if (std::abs(*begin - *(begin - 1)) < result)
            result = std::abs(*begin - *(begin - 1));

    return result;
}

Span::~Span() {}
