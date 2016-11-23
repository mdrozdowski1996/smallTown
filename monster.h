#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "citizen.h"

enum class beastType {
    Mummy,
    Zombie,
    Vampire
};

std::string beastTypeToString(beastType b);

template <typename T, beastType b>
class Monster: public MortalBeing<T>, public DamagingBeing<T> {
public:
    Monster(const T health, const T attackPower);
    using valueType = T;

    std::string getName() const;
};

template<typename T>
using Vampire = Monster<T, beastType::Vampire>;

template<typename T>
using Zombie = Monster<T, beastType::Zombie>;

template<typename T>
using Mummy = Monster<T, beastType::Mummy>;

template<typename M, typename U>
void attack(const M& monster, U& victim);

template<typename M, typename T>
void attack(M& monster, Sheriff<T>& victim);

#endif // MONSTER_H