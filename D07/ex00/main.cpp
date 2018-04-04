#include <iostream>
#include "whatever.cpp"

static void testChar(char x, char y)
{
    std::cout << "declare char x = " << x << ", y = " << y << std::endl;
    std::cout << "max : " << max(x, y) << std::endl;
    std::cout << "min : " << min(x, y) << std::endl;
    swap(x, y);
    std::cout << "after swap x = " << x << ", y = " << y << std::endl;
}

static void testFloat(float x, float y)
{
    std::cout << "declare float x = " << x << ", y = " << y << std::endl;
    std::cout << "max : " << max(x, y) << std::endl;
    std::cout << "min : " << min(x, y) << std::endl;
    swap(x, y);
    std::cout << "after swap x = " << x << ", y = " << y << std::endl;
}

static void testInt(int x, int y)
{
    std::cout << "declare int x = " << x << ", y = " << y << std::endl;
    std::cout << "max : " << max(x, y) << std::endl;
    std::cout << "min : " << min(x, y) << std::endl;
    swap(x, y);
    std::cout << "after swap x = " << x << ", y = " << y << std::endl;
}

int main()
{
    {
        int a = 2;
        int b = 3;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }
    {
        testInt(100, 110);
        testFloat(100, 110);
        testChar(100, 110);
    }
    return 0;
}