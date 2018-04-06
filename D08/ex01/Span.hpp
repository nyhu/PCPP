#ifndef __SPAN__
#define __SPAN__

#include <algorithm>
#include <stdexcept>
#include <cmath>

class Span {
    Span();
    std::vector<int> _container;
    std::vector<int>::iterator _it;

    public:
    Span(unsigned int n);
    Span(Span const &s);
    virtual ~Span();

    Span &operator=(Span const &s);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
};

#endif
