#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"


static void testNinjaSpecials(NinjaTrap &nt)
{
    ScavTrap s("sisi");
    ClapTrap c("coco");
    NinjaTrap n("nana");
    FragTrap f("fafa");

    nt.ninjaShoebox(s);
    nt.ninjaShoebox(c);
    nt.ninjaShoebox(n);
    nt.ninjaShoebox(f);
}

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

static void testCommuns(FragTrap &ft, ScavTrap &st, NinjaTrap &nt)
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

    NinjaTrap cccopy(nt);
    NinjaTrap tttest = cccopy;

    nt.takeDmg(35);
    nt.takeDmg(35);
    nt.takeDmg(100);

    nt.beRepaired(80);
    nt.beRepaired(80);

    nt.rangeAttack("farfaraway");
    nt.meleeAttack("closeTaget");
}

int main()
{
    NinjaTrap nt("naze");
    FragTrap ft("filou");
    ScavTrap st("saurien");
    testCommuns(ft, st, nt);
    testNinjaSpecials(nt);
    testScavSpecials(st);
    testFragSpecials(ft);
    return 0;
}