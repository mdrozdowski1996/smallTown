#ifndef MONSTER_H
#define MONSTER_H
#include "citizen.h"
#include <string>

template <typename T, std::string const& name>
class Monster: public MortalBeing<T>, public DamagingBeing<T> {
public:
    using valueType = T;
    Monster(const T health, const T attackPower);
};

// sth is wrong with that strigs
template<typename T>
using Vampire = Monster<T, "Vampire">;

template<typename T>
using Zombie = Monster<T, "Zombie">;

template<typename T>
using Mummy = Monster<T, "Mummy">;

/*template<typename M, typename U>
void attack(const M& monster, const U& victim);*/

#endif // MONSTER_H