#ifndef MININGBARGE_H
#define MININGBARGE_H

#include <iostream>
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

#define BARGE_CAPACITY 4

class MiningBarge
{

  public:
	MiningBarge(void);
	~MiningBarge();

	MiningBarge &operator=(MiningBarge const &rhs);

	void equip(IMiningLaser *laser);
	void mine(IAsteroid *a) const;

	IMiningLaser *minerSlot_[BARGE_CAPACITY];
};

#endif
