#include <assert.h>
#include "citizen.h"

// mortal
template <typename T>
T MortalBeing<T>::getHealth() const {
    return health;
}

template <typename T>
void MortalBeing<T>::takeDamage(const T damage) {
    health -= health >= damage ? damage : health;
}

template <typename T>
MortalBeing<T>::MortalBeing(const T health) : health(health) {}

// aged

template <typename T, T minAge, T maxAge>
void AgedBeing<T, minAge, maxAge>::age_assert() {
    assert(age <= maxAge && age >= minAge);
}

template <typename T, T minAge, T maxAge>
T AgedBeing<T, minAge, maxAge>::getAge() const {
    return age;
}

template <typename T, T minAge, T maxAge>
AgedBeing<T, minAge, maxAge>::AgedBeing(const T age) : age(age) {
    age_assert();
}
    
// damaging

template <typename T>
T DamagingBeing<T>::getAttackPower() const {
    return damage;
}

template <typename T>
DamagingBeing<T>::DamagingBeing(const T damage) : damage(damage) {}


// citizens

template <typename T, T minAge, T maxAge, defence defType>
Citizen<T, minAge, maxAge, defType>::Citizen(const T health, const  T age) :
    MortalBeing<T>(health),
    AgedBeing<T, minAge, maxAge>(age) {
}


template <typename T, T minAge, T maxAge>
Citizen<T, minAge, maxAge, defence::Armed>::Citizen(const T health, const T age, const T attackPower) :
    MortalBeing<T>(health),
    AgedBeing<T, minAge, maxAge>(age),
    DamagingBeing<T>(attackPower) {
}
