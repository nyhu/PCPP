#include <iostream>
#include <fstream>

static void cat_stream(std::istream &stream)
{
    std::string line;

    while (std::getline(stream, line))
        std::cout << line << std::endl;
}

static int open_stream(char *av)
{
    std::ifstream file(av);
    if (!file)
    {
        std::cerr << "cat: " << *av << ": No such file or directory" << std::endl;
        return 1;
    }
    cat_stream(file);
    return 0;
}

int main(int ac, char **av)
{
    bool haveError = false;
    if (ac <= 1)
    {
        cat_stream(std::cin);
        return 0;
    }
    while (*(++av))
        if (open_stream(*av))
            haveError = true;
    return haveError;
}
