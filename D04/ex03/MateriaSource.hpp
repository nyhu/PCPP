#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

#define SOURCE_SIZE 4

class MateriaSource : public IMateriaSource
{

  public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &rhs);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

	AMateria *inventory_[SOURCE_SIZE];
};

#endif
