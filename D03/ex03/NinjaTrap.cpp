#include "NinjaTrap.hpp"

void NinjaTrap::setDefaultSpec(std::string const &name)
{
    srand(time(0));
    this->_type = "NINJ4-TP";
    this->_name = name;
    this->_hitPt = 60;
    this->_maxHitPt = 60;
    this->_energyPt = 120;
    this->_maxEnergyPt = 120;
    this->_meleeDmg = 60;
    this->_rangeDmg = 5;
    this->_armorDmgReduction = 0;
}

NinjaTrap::NinjaTrap() : ClapTrap()
{
    this->setDefaultSpec("unkownNinjaBox");
    this->annonce();
}

NinjaTrap::NinjaTrap(const std::string name) : ClapTrap(name)
{
    this->setDefaultSpec(name);
    this->annonce();
}

NinjaTrap::NinjaTrap(const NinjaTrap &f) : ClapTrap()
{
    *this = f;
    this->annonce();
}

NinjaTrap::~NinjaTrap()
{
    this->denonce();
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &f)
{
    this->_type = f._type;
    this->_name = f._name;
    this->_lvl = f._lvl;
    this->_hitPt = f._hitPt;
    this->_maxHitPt = f._maxHitPt;
    this->_energyPt = f._energyPt;
    this->_maxEnergyPt = f._maxEnergyPt;
    this->_meleeDmg = f._meleeDmg;
    this->_rangeDmg = f._rangeDmg;
    this->_armorDmgReduction = f._armorDmgReduction;

    return *this;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &t)
{
    std::cout << this->_name
              << " meet another ninjatrap and he loves his kind"
              << std::endl;
    t.rangeAttack(this->_name);
    this->takeDmg(this->_rangeDmg);
    std::cout << "HELL YEAR! Hit me again my love" << std::endl;
    t.rangeAttack(this->_name);
    this->takeDmg(this->_rangeDmg);
    this->_energyPt = this->_maxEnergyPt;
    std::cout << "Ninja has recover all his NRJ point while being loved by his own family!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &t)
{
    std::cout << this->_name
              << " meet a claptrap and he hates them, after all, their are carrying ancestral basics dummy inheritance stuff"
              << std::endl;
    t.takeDmg(this->_meleeDmg);
    std::cout << "DIE FATHER" << std::endl;
    this->beRepaired(5);
    std::cout << "It feels so good I even recovered 5 hitPoints !" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &t)
{
    std::cout << this->_name
              << " meet a fragtrap and hide in shadows, them jump on him. Surprised it reacts badly:"
              << std::endl;
    t.vaulthunter_dot_exe(this->_name);
    std::cout << "Don't! I just wanted to hug you by your rear !" << std::endl;
    std::cout << "ClapTrap stop his special at the last second !" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &t)
{
    std::cout << this->_name
              << " meet a scavtrap and disguise in a newcommer"
              << std::endl;
    t.challengeNewcommer(this->_name);
    std::cout << this->_name
              << " really is a master of disguise ! Of course it will never try such a stupid challenge"
              << std::endl;
}
