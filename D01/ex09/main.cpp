#include "Logger.hpp"

int main(void) {
    Logger      human("example.test");

    human.log("logToFile", "coucou les amis");
    human.log("logToConsole", "coucou les copains");
    human.log("does not exist ", "coucou les méchant");
    return 0;
}