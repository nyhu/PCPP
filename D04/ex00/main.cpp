#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");

		std::cout << robert << jim << joe;

		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	{
		Peon joe("Joe");
		Peon joey = joe;
		Victim joel = joe;

		joe.getPolymorphed();
	}
	return (0);
}

/*
zaz@blackjack ex00 $ clang++ -W -Wall -Werror *.cpp
zaz@blackjack ex00 $ ./a.out | cat -e
Robert, the Magnificent, is born !$
Some random victim called Jimmy just popped !$
Some random victim called Joe just popped !$
Zog zog.$
I am Robert, the Magnificent, and I like ponies !$
I'm Jimmy and i like otters !$
I'm Joe and i like otters !$
Jimmy has been turned into a cute little sheep !$
Joe has been turned into a pink pony !$
Bleuark...$
Victim Joe just died for no apparent reason !$
Victim Jimmy just died for no apparent reason !$
Robert, the Magnificent, is dead. Consequences will never be the same !$
zaz@blackjack ex00 $
*/
