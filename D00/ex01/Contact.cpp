#include <iostream>
#include <iomanip> 
#include "Contact.hpp"

void Contact::addContact(void) {
    std::cout << "firstname:";
    std::cin >> this->firstName;
    std::cout << "lastname:";
    std::cin >> this->lastName;
    std::cout << "nickname:";
    std::cin >> this->nickName;
    std::cout << "login:";
    std::cin >> this->login;
    std::cout << "postal address:";
    std::cin >> this->postalAddress;
    std::cout << "email:";
    std::cin >> this->emailAddress;
    std::cout << "phone number:";
    std::cin >> this->phoneNumber;
    std::cout << "contact birth day date:";
    std::cin >> this->birthDay;
    std::cout << "contact favorite meal:";
    std::cin >> this->favoriteMeal;
    std::cout << "contact underwear color:";
    std::cin >> this->underwearColor;
    std::cout << "contact darkest secret:";
    std::cin >> this->darkestSecret;

    Contact::instancesNumber += 1;
}

Contact::~Contact() {
    Contact::instancesNumber -= 1;
}

void Contact::printLongVersion() const {
    std::cout << "firstname: " << this->firstName << std::endl;
    std::cout << "lastname: " << this->lastName << std::endl;
    std::cout << "nickname: " << this->nickName << std::endl;
    std::cout << "login: " << this->login << std::endl;
    std::cout << "postal address: " << this->postalAddress << std::endl;
    std::cout << "email: " << this->emailAddress << std::endl;
    std::cout << "phone number: " << this->phoneNumber << std::endl;
    std::cout << "contact birth day date: " << this->birthDay << std::endl;
    std::cout << "contact favorite meal: " << this->favoriteMeal << std::endl;
    std::cout << "contact underwear color: " << this->underwearColor << std::endl;
    std::cout << "contact darkest secret: " << this->darkestSecret << std::endl;
}

void shortString(std::string str) {
    if (str.length() > 10) {
        std::cout << std::right << str.substr(0, 9) << ".";
    } else {
        std::cout << std::right << std::setw(10) << str;
    }
}

void Contact::printShortVersion(int index) const {
    std::cout << std::right << std::setw(10) << index << "|";
    shortString(this->firstName);
    std::cout << "|";
    shortString(this->lastName);
    std::cout << "|";
    shortString(this->nickName);
    std::cout << std::endl;
}

int Contact::getInstancesNumber(void) {
    return Contact::instancesNumber;
}

int Contact::instancesNumber = 0;
