#ifndef __FILESYSTEM__
#define __FILESYSTEM__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileSystem {
public:
    FileSystem(std::string fileInput, std::string fileOutput);
    ~FileSystem();

    void replace(std::string s1, std::string s2);
    bool isInputOpen();
    bool isOutputOpen();

private:
    std::ifstream _fileInput;
    std::ofstream _fileOutput;
};

#endif