#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static int exitError(std::string error) {
    std::cout << error << std::endl;
    return 1;
}
static void replace(std::ifstream &fileInput,std::ofstream &fileOutput, std::string s1, std::string s2) {
    std::string line;
    while(!fileInput.eof()) {
        size_t offset = 0;
        std::getline(fileInput, line);
        while ((offset = line.find(s1, offset)) != std::string::npos) {
            std::cout << "found: " << s1 << " at position " << offset << std::endl;
            line.replace(offset, s1.length(), s2);
            offset += 1;
        }
        fileOutput << line << std::endl;
    }
}

static int openThenReplace(char* filename, std::string s1, std::string s2) {
    std::ifstream fileInput;
    fileInput.open(filename);
    if(!fileInput.is_open()) {
        return exitError("Unable to open source file.");
    }

    std::stringstream ss;
    std::ofstream fileOutput;
    ss << filename << ".replace";
    fileOutput.open(ss.str().c_str());
    if(!fileOutput.is_open()) {
        fileInput.close();
        return exitError("Unable to open destination file.");
    }

    replace(fileInput, fileOutput, s1, s2);

    fileInput.close();
    fileOutput.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        return exitError("not enough argument");
    }
    std::string filename = argv[1];
    std::string s1 = std::string(argv[2]);
    std::string s2 = std::string(argv[3]);
    if (filename == "" || s1 == "" || s2 == "") {
        return exitError("empty string are not accepted");
    }

    return openThenReplace(argv[1], s1, s2);
}