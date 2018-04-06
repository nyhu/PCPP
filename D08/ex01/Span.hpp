#ifndef __SPAN__
#define __SPAN__

#include <vector>
#include <stdexcept>
#include <cmath>

class Span {
    std::vector<int> _container;

    public:
    Span();
    Span(unsigned int n);
    Span(Span const &s);
    virtual ~Span();

    Span &operator=(Span const &s);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
};

#endif
