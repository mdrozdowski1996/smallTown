#ifndef CITIZEN_H
#define CITIZEN_H


// base classes

template<typename T>
class MortalBeing {
    T health;
public:
    T getHealth() const;
    void takeDamage(const T damage);

    MortalBeing(const T health);
};

template<typename T, T minAge, T maxAge>
class AgedBeing {
    T age;
    void age_assert();
public:
    T getAge() const;
    AgedBeing(const T age);
};

template<typename T>
class DamagingBeing {
    T damage;
public:
    T getAttackPower() const;
    DamagingBeing(const T damage);
};


// citizens

enum class defence {
    Vulnerable,
    Armed
};

template<typename T, T minAge, T maxAge, defence defType>
class Citizen : public MortalBeing<T>, public AgedBeing<T, minAge, maxAge> {
public:
    Citizen(const T health, const T age);
};

template<typename T, T minAge, T maxAge>
class Citizen<T, minAge, maxAge, defence::Armed> :
    public MortalBeing<T>, public AgedBeing<T, minAge, maxAge>, public DamagingBeing<T> {
public:
    Citizen(const T health, const T age, const T attackPower);
};


template<typename T>
using Adult = Citizen<T, 18, 100, defence::Vulnerable>;

template<typename T>
using Teenager = Citizen<T, 11, 17, defence::Vulnerable>;

template<typename T>
using Sheriff = Citizen<T, 18, 100, defence::Armed>;

#endif // CITIZEN_H