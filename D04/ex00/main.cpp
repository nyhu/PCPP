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
		Victim t;
		Victim v("Macron");
		Victim vv = v;

		Peon p;
		Peon joe("Joe");
		Peon joey = joe;
		Victim joel = joe;

		Sorcerer ss;
		Sorcerer src("Ladie", "Gaga");
		Sorcerer s = src;
		joe.getPolymorphed();
		ss.polymorph(joel);
		ss.polymorph(v);
		std::cout << joe << joey << joel << s << v;
	}
	return (0);
}
