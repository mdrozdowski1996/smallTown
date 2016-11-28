#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "citizen.h"

enum class monsterType {
    Mummy,
    Zombie,
    Vampire
};

std::string monsterTypeToString(monsterType b);

template <typename T, monsterType b>
class Monster: public MortalBeing<T>, public DamagingBeing<T> {
public:
    Monster(const T health, const T attackPower);
    using valueType = T;

    std::string getName() const;
};

template<typename T>
using Vampire = Monster<T, monsterType::Vampire>;

template<typename T>
using Zombie = Monster<T, monsterType::Zombie>;

template<typename T>
using Mummy = Monster<T, monsterType::Mummy>;

template<typename M, typename U>
void attack(const M& monster, U& victim);

template<typename M, typename T>
void attack(M& monster, Sheriff<T>& victim);




// IMPLEMENTATION


template <typename T, monsterType b>
Monster<T, b>::Monster(const T health, const T attackPower): MortalBeing<T>(health), DamagingBeing<T>(attackPower) {
}


inline std::string monsterTypeToString(monsterType b) {
    switch (b) {
    case monsterType::Mummy: return "Mummy";
    case monsterType::Zombie: return "Zombie";
    case monsterType::Vampire: return "Vampire";
    default: exit(1);
    }
}

template <typename T, monsterType b>
std::string Monster<T, b>::getName() const {
    return monsterTypeToString(b);
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
#endif // MONSTER_H
