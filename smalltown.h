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
void tick(U timeStep) � na pocz�tku sprawdza aktualny czas; je�li jest to
czas ataku, to nast�puje atak na wszystkich mieszka�c�w; na koniec czas
w miasteczku przesuwa si� o timeStep.

SmallTown operuje zgodnie z wewn�trznym zegarem.Czas liczony jest w godzinach,
od godziny 0 do godziny t1 i potem zn�w od godziny 0, i tak cyklicznie.Pierwsze
odliczanie zaczyna si� od godziny t0.Potw�r atakuje tylko o godzinach r�wnych
kolejnym liczbom z ci�gu Fibonacciego.Obliczenie wszystkich potrzebnych liczb
z tego ci�gu i ich zapami�tanie w jakiej� kolekcji musi odby� si� w czasie
kompilacji.

�mier� mieszka�ca b�d��potwora nast�puje w momencie, gdy jego liczba punkt�w
�ycia osi�gnie zero.Wywo�anie tick() na miasteczku z martwym potworem i co
najmniej jednym �ywym mieszka�cem powoduje wypisanie na standardowe wyj�cie
komunikatu "CITIZENS WON".Wywo�anie tick() na miasteczku z martwymi
mieszka�cami i �ywym potworem powoduje wypisanie na standardowym wyj�ciu napisu
"MONSTER WON".Je�li zar�wno miesza�cy, jak i potw�r s� martwi, to tick()
wypisuje na standardowe wyj�cie "DRAW".
*/
