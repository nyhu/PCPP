#ifndef __ENEMY_LIST__
#define __ENEMY_LIST__

#include "../ships/IShip.hpp"
#include "units/Fighter.hpp"
#include "units/Enforcer.hpp"
#include "units/Megatrope.hpp"
#include "../player/Player.hpp"

class EnemyList
{
  public:
    EnemyList();
    virtual ~EnemyList();
    EnemyList(EnemyList const & src);
    EnemyList &operator=(EnemyList const &rhs);


    bool operator>(int nb);

    void populateFighter(int nb);
    void populateEnforcer(int nb);
    void populateMegatrope(int nb);

    void move();
    void attack(BulletList &b);
    int computePlayfield(t_playfield &p, Player &p1, Player *p2, BulletList &b);

    IShip &getShip(int i);
    int   getNb();
    
  private:
    IShip *ships;
    int nb;
};

#endif