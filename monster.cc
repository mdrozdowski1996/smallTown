#include "monster.h"

template <typename T, std::string const& name>
Monster<T, name>::Monster(const T health, const T attackPower) : MortalBeing<T>(health), DamagingBeing<T>(attackPower) {}

template <typename M, typename U>
void attack(const M& monster, const U& victim) {
    victim.takeDamage(monster.getAttackPower());
}

/*template <typename M, typename Sheriff<T> >
void attack(const M& monster, const Sheriff<T>& rival) {
    rival.takeDamage(monster.getAttackPower());
    monster.takeDamage(rival.getAttackPower());
}*/
