#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Robotnik.h"

void Robotnik::drukuj_osobe()
{
  cout << " Pracownik na stanowisku\tRobotnik,\t imie jego to " << imie;
  cout << ",\t\tjego rozmiar buta to " << spec << "." << endl;
   }

int Robotnik::getWynagrodzenie() {
    return wynagrodzenie;
}

int Robotnik::get_teorWypr_produkty() {
    return stala;
}