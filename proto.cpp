#include <vector>
#include <utility> //pair
using namespace std;
class Genome{
public:
    vector<double>  Genome;
};
//w konstruktorze klasy losowanie liczb dla Genomeu
//czy my to losowanie do Genomeu mamy zrobic funkcjami z CEC 2017?

class Populacja {
public:
    vector<Genome> Populacja;
};

void generujPopulacje(int rozmiarPopulacji); //chyba mozna tez zrobic jako konstruktor?

void ocenaPopulacji(Populacja aktualnaPopulacja); //sprawdzamy, czy ta populacja spelnia juz nasze wymagania
// ALE na jakiej podstawie my decydujemy, ze cos jest lepsze, a cos gorsze?


double znajdzNajlepszego(Populacja aktualnaPopulacja); //jest na slajdach ale idk czy to potrzebne - mozna sortowac jak ziomek z YT
pair<Genome, Genome> selekcja(Populacja aktualnaPopulacja); //wybor pary, ktora bedziemy krzyzowac - trzeba tak zrobic, zeby nie wybieral zawsze tych samych
pair<Genome, Genome> krzyzowanie(pair<Genome, Genome> rodzice); //wymiana czesci genow
Genome mutacja(Genome mutowany); //dodatkowa zmiana po krzyzowan iu


// model wyspowy
class ModelWyspowy{

public:

    vector<Populacja> Wyspy;
};

//ile osobników z każdej wyspy, trzeba będzie zadbać o to żeby każda wyspa dostała tyle samo migrantów
void migracja(vector<Populacja> wyspy, int rozmiarMigracji){
}
//funkcja realizująca pojedyńczą migrację (w jedna stronę, czy w dwie? tzn z A idą do B a z B do A)
void migracjaSkladowa(Populacja &zrodlo, Populacja &destynacja, int romziarMigracji){
}



double ewolucja(Populacja aktualnaPopulacja){
    //generujPopulacje(10); <<================== zakomentowane !!!

    //caly proces ewolucji - dopoki nie znajdziemy optymalnego (czyli jakiego?) lub nie przekroczymy liczby pokolen

    // na koniec nowa generacja - potomstwo + 2 najlepsze z poprzedniej populacji
    return 0;
};
