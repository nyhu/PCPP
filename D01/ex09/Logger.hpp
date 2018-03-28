
#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <ctime>

class Logger {

public:
    Logger(std::string name);
    ~Logger();
    void log(std::string const & dest, std::string const & message);

private:
    void logToConsole(std::string const & inpout);
    void logToFile(std::string const & inpout);
    std::string _displayTimestamp(void);
    std::string makeLogEntry(std::string const & inpout);

    std::string nameFile;
};

#endif