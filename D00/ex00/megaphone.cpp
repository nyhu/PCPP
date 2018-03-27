#include <iostream>
#include <limits>

char* strToUpper(char *str) {
    char *p;

    p = str;
    while (*p) {
        *p = std::toupper(*p);
        p++;
    }
    return str;
}

int main (int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::cout << strToUpper(argv[i]);
    }
    std::cout << std::endl;
    return 0;
}