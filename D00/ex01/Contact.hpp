#ifndef __CONTACT__
# define __CONTACT__

#include <string>

#define CONTACT_MAX 8

class Contact {
public:
    void addContact(void); 
    static int getInstancesNumber(void);
    void printShortVersion(int index) const;
    void printLongVersion() const;
    ~Contact(void);
    
private:
    static int instancesNumber;

    std::string firstName;
    std::string lastName;
    std::string nickName;

    std::string login;
    std::string postalAddress;
    std::string emailAddress;
    std::string phoneNumber;
    std::string birthDay;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;
};

#endif