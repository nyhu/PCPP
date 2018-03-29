#include "FragTrap.hpp"

static void testAttacks(FragTrap &ft)
{
    ft.rangeAttack("farfaraway");
    ft.meleeAttack("closeTaget");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
}

static void testConstructors(FragTrap const &ft)
{
    FragTrap copy(ft);
    FragTrap test = copy;

    copy.takeDmg(35);
    copy.takeDmg(100);
    copy.takeDmg(35);

    copy.beRepaired(80);
    copy.beRepaired(80);
}

int main()
{
    FragTrap ft("papaye");
    testConstructors(ft);
    testAttacks(ft);
    return 0;
}