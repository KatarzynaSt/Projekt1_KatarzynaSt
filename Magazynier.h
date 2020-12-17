#pragma once
#include "Pracownik.h"
#ifndef MAGAZYNIER_H
#define MAGAZYNIER_H

using namespace std;

class Magazynier : public Pracownik
{
public:
    Magazynier(int spec, string imie) :Pracownik(imie) , spec(spec)
    {
        if (spec == 3) {
            ff = "nie umie obslugiwac wozka widlowego.";
        }
        else if (spec == 1)
        {
            ff = "umie obslugiwac wozek widlowy.";
        }
        else if (spec == 2)
        {
            ff = "umie obslugiwac wozek widlowy.";
        }
    }
    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
    virtual int get_PojemoscMagazynu();


protected:
    int spec;
    static const int stala = 3; // wzrost pojemnosci magazynu o x
    static const int wynagrodzenie = 17; //wynagrodzenie Magazyniera
    string ff;
};

#endif // !MAGAZYNIER_H

