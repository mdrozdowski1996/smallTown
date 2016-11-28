#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include <vector>
#include <tuple>
#include <cstdio>
#include <algorithm>
#include "monster.h"

template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
    static_assert(t0 <= t1, "Wrong times");

    std::tuple<C...> citizens;
    //std::vector<int> fibonacci;
	std::vector<int> aliveIndex;
    M monster;
    U actTime;
public:

    SmallTown(M monster, C ... citizens);
    template<typename T>
    std::tuple<std::string, T, size_t> getStatus();
    void tick(U timeStep);
};



template <typename M, typename U, U t0, U t1, typename ... C>
SmallTown<M, U, t0, t1, C...>::SmallTown(M monster, C... citizens) : citizens(citizens), monster(monster), actTime(t0) {
	int s = citizens.size();
	for (int i = 0; i < s; i++) {
		if (std::get<i>(citizens).getHealth() > 0) {
			aliveIndex.push_back(i);
		}
	} 
}


template<typename M, typename U, U t0, U t1, typename ...C>
void SmallTown<M, U, t0, t1, C...>::tick(U timeStep) {
    bool allDead = true;

    for (auto it : citizens) {
        if (it.getHealth() > 0 ) {
            allDead = false;
            break;
        }
    }

    if (monster.getHealth == 0 && allDead) {
        printf("DRAW\n");
    }
    else if (monster.getHealth == 0) {
        printf("CITIZENS WON\n");
    }
    else if (allDead) {
        printf("MONSTER WON\n");
    }

    if (std::find(fibonacci.begin(), fibonacci.end(), actTime) != fibonacci.end()) {
		std::vector<int> stillAlive;
		int elt;
        while (!aliveIndex.empty()) {
			elt = aliveIndex.back();
			aliveIndex.pop_back();
			
            attack(monster, std::get<it>(citizens)); // monster attacks simultaneously
            
            if (std::get<it>(citizens).getHealth > 0) {
				stillAlive.push_back(it);
			}
        }
        
        std::swap(stillAlive, aliveIndex);
        stillAlive.clear();
    }

    actTime += timeStep;
    actTime %= (t1 + 1);
}

template <typename M, typename U, U t0, U t1, typename ... C>
template <typename T>
std::tuple<std::string, T, size_t> SmallTown<M, U, t0, t1, C...>::getStatus() {
    return {monster.getName(), monster.getHealth(), citizens.size()};
}

#endif
