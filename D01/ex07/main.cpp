#include "FileSystem.hpp"

static int exitError(std::string error) {
    std::cout << error << std::endl;
    return 1;
}

static int openThenReplace(char* filename, std::string s1, std::string s2) {
    std::stringstream ss;
    ss << filename << ".replace";
    FileSystem fileSystem(filename, ss.str());
    
    if (!fileSystem.isInputOpen() || !fileSystem.isOutputOpen()) {
        return exitError("unable to open file");
    }

    fileSystem.replace(s1, s2);
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
