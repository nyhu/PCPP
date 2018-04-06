#include "Span.hpp"
#include <iostream>

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(3);
        try
        {
            sp.shortestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            sp.longestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        sp.addNumber(-1);
        sp.addNumber(1);
        sp.addNumber(2);
        try
        {
            sp.addNumber(-1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        Span cp = sp;
        std::cout << cp.shortestSpan() << std::endl;
        std::cout << cp.longestSpan() << std::endl;
    }
}