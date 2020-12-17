#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Pracownik.h"

#ifndef MARKETER_H
#define MARKETER_H

class Marketer : public Pracownik
{
public:
    Marketer(int spec, string imie) : spec(spec), Pracownik(imie)
    { };

    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
    virtual int get_popyt();

protected:
    int spec;
    static const int stala = 4; // wzrost popytu (ilosci sprzedanych produktow w miesiacu) o x
    static const int wynagrodzenie = 16; //wynagrodzenie Marketera
};

#endif //!MARKETER_H