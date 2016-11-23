#ifndef SMALLTOWN_H
#define SMALLTOWN_H
#include <vector>

template <typename M, typename U, U t0, U t1, typename... C>
class SmallTown {
    static_assert(t0 <= t1, "Wrong times");
    std::vector<C> citizens;
    M monster;
    std::vector<int> fibonacci;
    U actTime;
public:
    SmallTown(M monster, C ... citizens);
    template<typename T>
    std::tuple<std::string, T, size_t> getStatus();
    void tick(U timeStep);
};




#endif
/*
void tick(U timeStep) – na pocz¹tku sprawdza aktualny czas; jeœli jest to
czas ataku, to nastêpuje atak na wszystkich mieszkañców; na koniec czas
w miasteczku przesuwa siê o timeStep.

SmallTown operuje zgodnie z wewnêtrznym zegarem.Czas liczony jest w godzinach,
od godziny 0 do godziny t1 i potem znów od godziny 0, i tak cyklicznie.Pierwsze
odliczanie zaczyna siê od godziny t0.Potwór atakuje tylko o godzinach równych
kolejnym liczbom z ci¹gu Fibonacciego.Obliczenie wszystkich potrzebnych liczb
z tego ci¹gu i ich zapamiêtanie w jakiejœ kolekcji musi odbyæ siê w czasie
kompilacji.

Œmieræ mieszkañca b¹dŸ potwora nastêpuje w momencie, gdy jego liczba punktów
¿ycia osi¹gnie zero.Wywo³anie tick() na miasteczku z martwym potworem i co
najmniej jednym ¿ywym mieszkañcem powoduje wypisanie na standardowe wyjœcie
komunikatu "CITIZENS WON".Wywo³anie tick() na miasteczku z martwymi
mieszkañcami i ¿ywym potworem powoduje wypisanie na standardowym wyjœciu napisu
"MONSTER WON".Jeœli zarówno mieszañcy, jak i potwór s¹ martwi, to tick()
wypisuje na standardowe wyjœcie "DRAW".
*/
