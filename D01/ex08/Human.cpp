#include "Human.hpp"

void Human::action(std::string const &action_name, std::string const &target)
{
    typedef void (Human::*func)(std::string const &);
    std::map<std::string, func> funcMap;

    funcMap.insert(std::make_pair("meleeAttack", &Human::meleeAttack));
    funcMap.insert(std::make_pair("rangedAttack", &Human::rangedAttack));
    funcMap.insert(std::make_pair("intimidatingShout", &Human::intimidatingShout));
    if (funcMap.count(action_name) > 0)
    {
        func chose = funcMap[action_name];
        (this->*chose)(target);
    }
    else
    {
        std::cout
            << "I don't know how to "
            << action_name
            << " "
            << target
            << " !"
            << std::endl;
    }
}

void Human::meleeAttack(std::string const &target)
{
    std::cout << "Take this knive in you face "
              << target
              << " !"
              << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
    std::cout << "Take this bullet in you face "
              << target
              << " !"
              << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
    std::cout << "I will make you feel pain "
              << target
              << " !"
              << std::endl;
}
