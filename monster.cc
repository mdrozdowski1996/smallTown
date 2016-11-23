#include "monster.h"

template <typename T, beastType b>
Monster<T, b>::Monster(const T health, const T attackPower) : MortalBeing<T>(health), DamagingBeing<T>(attackPower) {}


std::string beastTypeToString(beastType b) {
    switch (b) {
    case beastType::Mummy: return "Mummy";
    case beastType::Zombie: return "Zombie";
    case beastType::Vampire: return "Vampire";
    default: exit(1);
    }
}

template <typename T, beastType b>
std::string Monster<T, b>::getName() const {
    return beastTypeToString(s);
}

template <typename M, typename U>
void attack(const M& monster, U& victim) {
    victim.takeDamage(monster.getAttackPower());
}

template <typename M, typename T>
void attack(M& monster, Sheriff<T>& rival) {
    rival.takeDamage(monster.getAttackPower());
    monster.takeDamage(rival.getAttackPower());
}
