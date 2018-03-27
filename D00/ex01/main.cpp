#include <iostream>
#include <iomanip> 
#include <limits> 
#include "Contact.hpp"

static void search(Contact *contacts) {
    std::cout << std::right << std::setw(10) << "INDEX" << "|";
    std::cout << std::right << std::setw(10) << "FIRST NAME" << "|";
    std::cout << std::right << std::setw(10) << "LAST NAME" << "|";
    std::cout << std::right << std::setw(10) << "NICK NAME" << std::endl;
    int i;
    
    for (i = 0; i < Contact::getInstancesNumber(); i++) {
        contacts[i].printShortVersion(i);
    }

    std::cout << "Enter index from contact you desire the most:";
    if (!(std::cin >> i) 
        || !(i >= 0 && i < Contact::getInstancesNumber())) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "invalid index, what a shame,";
        std::cout << " you'll have to restart your research !" << std::endl;
        return;
    }

    contacts[i].printLongVersion();                
}

static void add(Contact *contacts) {
    if (Contact::getInstancesNumber() == CONTACT_MAX) {
        std::cout << "Your company reach the free plan limit,";
        std::cout << " megaphone us to get more contacts" << std::endl;
        return;
    }

    contacts[Contact::getInstancesNumber()].addContact();
}

int main() {
    std::string buf;
    Contact contacts[CONTACT_MAX];

    while (std::cin.eof() != 1) {
        std::cout << "What would you like to do ?" << std::endl;
        std::cout << "ADD a contact, SEARCH one, or EXIT: ";
        if (!(std::cin >> buf)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (buf.compare("EXIT") == 0) {
            return 0;
        }
        if (buf.compare("ADD") == 0) {
            add(contacts);
        }
        if (buf.compare("SEARCH") == 0) {
            search(contacts);
        }
    }
    return 0;
}