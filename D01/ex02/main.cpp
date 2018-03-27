#include "Zombie.hpp"
#include "ZombieEvent.hpp"

/* Charly is a known heapZombie */
int main() {
    ZombieEvent zombieFactory;
    Zombie *charly;

    charly = zombieFactory.newZombie("Charly");
    charly->annonce();
    delete charly;

    zombieFactory.randomChump();

    zombieFactory.setZombieType("runners");
    zombieFactory.randomChump();

    Zombie stackZombie("Charly", "charlos");
    stackZombie.annonce();

    return 0;
}