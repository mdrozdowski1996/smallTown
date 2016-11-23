#ifndef CITIZEN_H
#define CITIZEN_H

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
    T getDamage() const;
    DamagingBeing(const T damage);
};

typedef enum {
    vulnerable,
    armed
} defence;

template<typename T, T minAge, T maxAge, defence defType>
class Citizen: public MortalBeing<T>, public AgedBeing<T, minAge, maxAge> {
public:
    Citizen(const T health, const T age);
};

template<typename T, T minAge, T maxAge>
class Citizen<T, minAge, maxAge, armed>: public AgedBeing<T, minAge, maxAge>, public MortalBeing<T>, public DamagingBeing<T> {
public:
    Citizen(const T health, const T age, const T attackPower);
};


template<typename T>
using Adult = Citizen<T, 18, 100, vulnerable>;

template<typename T>
using Teenager = Citizen<T, 11, 17, vulnerable>;

template<typename T>
using Sheriff = Citizen<T, 18, 100, armed>;

#endif // CITIZEN_H