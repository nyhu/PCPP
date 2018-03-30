#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(NULL); //

	ICharacter *zaz = new Character("zaz");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);

	tmp = src->createMateria("/dev/urandom");
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	zaz->equip(NULL);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("cure");

	ICharacter *bob = new Character("bob");

	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(42, *bob);
	zaz->use(-1, *bob);

	delete bob;
	delete zaz;
	delete src;

	return (0);
}
