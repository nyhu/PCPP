#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

int main(void)
{
	CentralBureaucracy c;
	std::string names [20] = {
		"Macron",
		"Copé",
		"Marie",
		"Malice",
		"Ababar",
		"Iloe",
		"Alice",
		"Illiad",
		"Omarand",
		"Kallissi",
		"Lpams",
		"Moo",
		"Qlad",
		"Fafa",
		"Hawaien",
		"Mateo",
		"Durand",
		"Dupond",
		"Dupont"
	};
	Bureaucrat *b[OFFICES_NB];
	for (int i = 0; i < OFFICES_NB; i++) {
		b[i] = new Bureaucrat(names[i], rand()%150 + 1);
		c.feed(*b[i]);
	}
	for (int i = 0; i < MAX_REQUESTER; i++)
		c.queueUp(names[rand()%20]);
	c.doBureaucracy();
	return 0;
}
