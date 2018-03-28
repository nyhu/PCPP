#include "Logger.hpp"

Logger::Logger(std::string nameFile)
{
    this->nameFile = nameFile;
}

Logger::~Logger()
{
}

void Logger::logToConsole(std::string const &input)
{
    std::cout << input << std::endl;
}

void Logger::logToFile(std::string const &input)
{
    std::ofstream out(this->nameFile.c_str(), std::ios::app);
    out << input << std::endl;
    out.close();
}

std::string Logger::makeLogEntry(std::string const &input)
{
    std::string str = _displayTimestamp() + " | " + input;

    return str;
}

void Logger::log(std::string const &dest, std::string const &message)
{
    typedef void (Logger::*func)(std::string const &);
    std::map<std::string, func> funcMap;
    std::string str = this->makeLogEntry(message);

    funcMap.insert(std::make_pair("logToFile", &Logger::logToFile));
    funcMap.insert(std::make_pair("logToConsole", &Logger::logToConsole));
    if (funcMap.count(dest) > 0)
    {
        func chose = funcMap[dest];
        (this->*chose)(str);
    } else {
        logToConsole(str);
    }
}

std::string Logger::_displayTimestamp(void)
{
    char str[100];
    std::time_t t;

    std::time(&t);
    std::strftime(str, sizeof(str), "%Y/%m/%d %H:%M:%S", std::localtime(&t));
    return str;
}
