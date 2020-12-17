#pragma once
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

#ifndef PRACOWNIK_H
#define PRACOWNIK_H


class Pracownik 
{
public:
   Pracownik() {};
   Pracownik(string imie) : imie(std::move(imie)) {};

   virtual void drukuj_osobe();
   virtual int getWynagrodzenie();
   virtual int get_teorWypr_produkty();
   virtual int get_popyt();
   virtual int get_PojemoscMagazynu();
   virtual int get_wzrost_ceny_produktu();

   virtual ~Pracownik() { cout << "Strajk generalny, pracownik Cie opuscil." << endl; }

protected:
    string imie;
};


#endif // !PRACOWNIK_H

