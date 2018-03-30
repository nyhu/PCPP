#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"


static void testNinjaSpecials(NinjaTrap &nt)
{
    std::cout << std::endl << "NINJA SPE TESTS" << std::endl;
    
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
    std::cout << std::endl << "SCAV SPE TESTS" << std::endl;
    
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
    st.challengeNewcommer("poorNewcommer");
}

static void testFragSpecials(FragTrap &ft)
{
    std::cout << std::endl << "FRAG SPE TESTS" << std::endl;
    
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
    ft.vaulthunter_dot_exe("poorBandit");
}

static void testCommuns(FragTrap &ft, ScavTrap &st, NinjaTrap &nt, SuperTrap &sut)
{
    std::cout << std::endl << "STD TESTS" << std::endl;

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

    SuperTrap ccccopy(sut);
    SuperTrap ttttest = ccccopy;

    sut.takeDmg(35);
    sut.takeDmg(35);
    sut.takeDmg(100);

    sut.beRepaired(80);
    sut.beRepaired(80);

    sut.rangeAttack("farfaraway");
    sut.meleeAttack("closeTaget");
}

int main()
{
    NinjaTrap nt("naze");
    FragTrap ft("filou");
    ScavTrap st("saurien");
    SuperTrap sut("Super Tramp");

    testCommuns(ft, st, nt, sut);
    testNinjaSpecials(nt);
    testScavSpecials(st);
    testFragSpecials(ft);
    testNinjaSpecials(sut);
    testFragSpecials(sut);
    return 0;
}