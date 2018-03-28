#include "FileSystem.hpp"

FileSystem::FileSystem(std::string fileInput, std::string fileOutput) {
    if (fileInput != "") {
        this->_fileInput.open(fileInput.c_str());
    }
    if (fileOutput != "") {
        this->_fileOutput.open(fileOutput.c_str());
    }
}

FileSystem::~FileSystem(){
    if (this->isInputOpen()) {
        this->_fileInput.close();
    }
    if (this->isOutputOpen()) {
        this->_fileOutput.close();
    }
}

bool FileSystem::isInputOpen() {
    return this->_fileInput.is_open();   
}

bool FileSystem::isOutputOpen() {
    return this->_fileOutput.is_open();       
}

void FileSystem::replace(std::string s1, std::string s2) {
    std::string line;
    while(!this->_fileInput.eof()) {
        size_t offset = 0;
        if (std::getline(this->_fileInput, line)) {
       		while ((offset = line.find(s1, offset)) != std::string::npos) {
        	    std::cout << "found: " << s1 << " at position " << offset << std::endl;
        	    line.replace(offset, s1.length(), s2);
        	    offset += 1;
        	}
        	this->_fileOutput << line << std::endl;
		}
    }
}
