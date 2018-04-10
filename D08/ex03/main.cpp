#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <exception>

// #define MO_INCREM '>'
// #define MO_DECREM '<'
// #define MO_UP '+'
// #define MO_DOWN '-'
// #define MO_PRINT '.'
// #define MO_NEXT '['
// #define MO_PREV ']'

#define MO_INCREM 'n'
#define MO_DECREM 'y'
#define MO_UP 'h'
#define MO_DOWN 'u'
#define MO_PRINT '?'
#define MO_NEXT '>'
#define MO_PREV '<'

typedef void (*func)(std::vector<char> &, std::vector<char>::iterator &);

static void goNext(std::list<char> const &instructions, std::list<char>::iterator &listIt)
{
    long nb = 0;
    while (listIt != instructions.end() && listIt != instructions.begin())
    {
        if (*listIt == MO_NEXT)
            ++nb;
        if (*listIt == MO_PREV)
            --nb;
        if (nb < 0)
            listIt--;
        if (nb > 0)
            listIt++;
        if (!nb)
            return;
    }
    throw std::logic_error("ptr went out of range when going to next parenthesis");
}

static void moIncrm(std::vector<char> &v, std::vector<char>::iterator &it)
{
    if (it == v.end())
        throw std::logic_error("ptr went out of range during incrementation");
    it++;
}

static void moDecrem(std::vector<char> &v, std::vector<char>::iterator &it)
{
    if (it == v.begin())
        throw std::logic_error("ptr went out of range during decrementation");
    it--;
}

static void moPrint(std::vector<char> &v, std::vector<char>::iterator &it)
{
    (void)v;
    std::cout << *it;
}

static void moUp(std::vector<char> &v, std::vector<char>::iterator &it)
{
    (void)v;
    (*it)++;
}

static void moDown(std::vector<char> &v, std::vector<char>::iterator &it)
{
    (void)v;
    (*it)--;
}

static void recurse(
    std::map<char, func> &instructionHandler,
    std::vector<char> &v, std::vector<char>::iterator &it,
    std::list<char> const &instructions, std::list<char>::iterator &listIt)
{
    if (instructionHandler.count(*listIt) > 0)
        instructionHandler[*listIt](v, it);

    if ((*listIt == MO_PREV && *it != 0) || (*listIt == MO_NEXT && *it == 0))
        goNext(instructions, listIt);

    listIt++;
    if (listIt == instructions.end()) {
        std::cout << std::endl;
        return;
    }
    recurse(instructionHandler, v, it, instructions, listIt);
}

static void execute(std::list<char> instructions, size_t vectorSize)
{
    std::vector<char> vector(vectorSize, 0);
    std::map<char, func> instructionHandler;
    std::vector<char>::iterator mindOpen = vector.begin();
    std::list<char>::iterator listIt = instructions.begin();

    std::cout << "result using vector size = " << vectorSize << ":" << std::endl;

    instructionHandler[MO_INCREM] = moIncrm;
    instructionHandler[MO_DECREM] = moDecrem;
    instructionHandler[MO_UP] = moUp;
    instructionHandler[MO_DOWN] = moDown;
    instructionHandler[MO_PRINT] = moPrint;

    recurse(instructionHandler, vector, mindOpen, instructions, listIt);
}

static void translate(std::string const &file)
{
    std::cout << "translating:" << std::endl
              << file << std::endl;

    size_t vectorSize = 1;
    std::list<char> instructions;
    for (size_t i = 0; i < file.length(); i++)
    {
        if (file[i] == MO_INCREM)
            ++vectorSize;
        instructions.push_back(file[i]);
    }

    execute(instructions, vectorSize);
}

int main(int ac, char **argv)
{
	if (ac == 1)
	{
		std::cout << "usage: ./openminder <filename> [<otherfilesnames>]" << std::endl;
	}
    for (int i = 1; i < ac; i++)
    {
        std::ifstream inputFile(argv[i]);
        if (!inputFile.is_open())
        {
            std::cout << "mindopener error: cannot open " << argv[i] << std::endl;
            continue;
        }

        std::string file;
        std::string line;
        while (getline(inputFile, line))
            file += line;
        inputFile.close();
 
		try {
			translate(file);
		}
		catch (std::exception &e) {
			std::cout << "mindopener error on file: " << argv[i] << ": " << e.what() << std::endl;
		}
    }
    return 0;
}
