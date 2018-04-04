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
    testInt(100, 110);
    testFloat(100, 110);
    testChar(100, 110);

    return 0;
}