#include <iostream>
#include <string>
#include "Squad.hpp"

Squad::Squad(void) : _list(NULL), _count(0)
{
}

Squad::Squad(Squad const &src) : _list(NULL), _count(0)
{
	this->cloneFrom(src);
}

Squad::~Squad()
{
	this->destroyChilds();
}

int Squad::getCount() const
{
	return this->_count;
}

ISpaceMarine *Squad::getUnit(int index) const
{
	t_unit *tmp = this->_list;
	int i = 0;

	while (tmp && i < this->_count)
	{
		if (i == index)
		{
			return tmp->unit;
		}
		tmp = tmp->next;
		i++;
	}
	return NULL;
}

int Squad::push(ISpaceMarine *marine)
{
	// we don't want an already existing marine
	if (!marine || this->alreadyHas(marine, this->_list))
		return this->_count;

	if (!this->_list)
	{
		this->_list = new (t_unit);
		this->_list->unit = marine;
		this->_list->next = NULL;
	}
	else
	{
		t_unit *tmp = this->_list;
		while (tmp->next)
		{
			if (tmp->unit == marine)
				return (this->_count);
			tmp = tmp->next;
		}
		tmp->next = new (t_unit);
		tmp->next->unit = marine;
		tmp->next->next = NULL;
	}
	this->_count++;
	return this->_count;
}

bool Squad::alreadyHas(ISpaceMarine *marine, t_unit *head)
{
	while (head)
	{
		if (marine == head->unit)
			return true;
		head = head->next;
	}
	return false;
}

void Squad::destroyChilds(void)
{
	t_unit *tmp;

	while (this->_list)
	{
		tmp = this->_list;
		if (this->_list->unit)
		{
			delete this->_list->unit;
			this->_list->unit = NULL;
		}
		this->_list = this->_list->next;
		delete tmp;
	}
	this->_list = NULL;
}

void Squad::cloneFrom(const Squad &src)
{
	for (int i = 0; i < src.getCount(); i++)
	{
		this->push(src.getUnit(i));
	}
}

std::ostream &operator<<(std::ostream &o, Squad const &squad)
{
	o << "Squad: " << squad.getCount() << " members" << std::endl;

	return o;
}

Squad &Squad::operator=(const Squad &rhs)
{
	(void)rhs;
	return (*this);
}
