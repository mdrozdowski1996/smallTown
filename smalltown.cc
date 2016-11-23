#include "smalltown.h"
#include <cstdio>
#include <algorithm>

template <typename M, typename U, U t0, U t1, typename ... C>
SmallTown<M, U, t0, t1, C...>::SmallTown(M monster, C... citizens) : citizens(citizens), monster(monster), actTime(t0) {}

template<typename M, typename U, U t0, U t1, typename ...C>
void SmallTown<M, U, t0, t1, C...>::tick(U timeStep) {
    if (monster.getHealth == 0 && citizens.empty()) {
        printf("DRAW\n");
    }
    else if (monster.getHealth == 0) {
        printf("CITIZENS WON\n");
    }
    else if (citizens.empty()) {
        printf("MONSTER WON\n");
    }

    actTime += timeStep;
    if (std::upper_bound(fibonacci.begin(), fibonacci.end(), actTime) == actTime) {
        for (auto it : citizens) {
            attack(monster, it); // monster attacks simultaneously
        }
        std::vector<C> notDead;
        for (auto it : citizens) {
            if (it.getHealth() > 0) {
                notDead.add(it);
            }
        }
        std::swap(notDead, citizens);
    }
}



template <typename M, typename U, U t0, U t1, typename ... C>
template <typename T>
std::tuple<std::string, T, size_t> SmallTown<M, U, t0, t1, C...>::getStatus() {
    return {, monster.getHealth(), citizens.size()};
}
