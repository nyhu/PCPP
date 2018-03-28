#include "Human.hpp"

int main() {
    Human	attack;

	attack.action("meleeAttack", "Arthur");
	attack.action("rangedAttack", "Charly");
	attack.action("intimidatingShout", "Gaston");
    
	attack.action("fart", "shit");
    
    return 0;
}