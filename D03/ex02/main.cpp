#include "FragTrap.hpp"
#include "ScavTrap.hpp"


static void testScavSpecials(ScavTrap &st)
{
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
}

static void testFragSpecials(FragTrap &ft)
{
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
}

static void testCommuns(FragTrap &ft, ScavTrap &st)
{
    FragTrap copy(ft);
    FragTrap test = copy;

    ft.takeDmg(35);
    ft.takeDmg(35);
    ft.takeDmg(100);

    ft.beRepaired(80);
    ft.beRepaired(80);

    ft.rangeAttack("farfaraway");
    ft.meleeAttack("closeTaget");

    ScavTrap ccopy(st);
    ScavTrap ttest = ccopy;

    st.takeDmg(35);
    st.takeDmg(35);
    st.takeDmg(100);

    st.beRepaired(80);
    st.beRepaired(80);
    st.rangeAttack("farfaraway");
    st.meleeAttack("closeTaget");

}

int main()
{
    FragTrap ft("filou");
    ScavTrap st("saurien");
    testCommuns(ft, st);
    testFragSpecials(ft);
    testScavSpecials(st);
    return 0;
}