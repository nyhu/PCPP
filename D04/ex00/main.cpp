#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
		std::cout << "42 tests" << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");

		std::cout << robert << jim << joe;

		robert.polymorph(jim);
		robert.polymorph(joe);
	}
		std::cout <<std::endl << "PERSO tests" << std::endl;
	{
		Peon joe("Joe");
		Peon joey = joe;
		Victim joel = joe;

		joe.getPolymorphed();
	}
	return (0);
}
