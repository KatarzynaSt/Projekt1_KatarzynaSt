#pragma once
#include "Pracownik.h"
#ifndef ROBOTNIK_H
#define ROBOTNIK_H

class Robotnik : public Pracownik
{
public:
    Robotnik(int spec, string imie) : spec(spec), Pracownik(imie)
    {};

    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
    virtual int get_teorWypr_produkty();
  

protected:
    int spec;
    static const int stala = 5; // wzrost podazy (ilosci wyprodukowanych teoretycznie produktow) o x
    static const int wynagrodzenie = 15; //wynagrodzenie Robotnika
};

#endif // !ROBOTNIK_H