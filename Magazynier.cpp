#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Magazynier.h"


void Magazynier::drukuj_osobe()
{
    cout << " Pracownik na stanowisku\tMagazynier,      imie jego to " << imie;
    cout << ",\t\t" << ff << endl;
}


int Magazynier::getWynagrodzenie() 
{
    return wynagrodzenie;
}

int Magazynier::get_PojemoscMagazynu()
{
    return stala;
}