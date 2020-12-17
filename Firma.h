#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>
#include "Pracownik.h"
#include <list>
#include "Kredyt.h"
#pragma once
#ifndef FIRMA_H
#define FIRMA_H

class Firma
{
public:
	Firma()
	{
		zatrudnij_inzyniera();
		zatrudnij_magazyniera();    
		zatrudnij_marketera();   
		zatrudnij_robotnika();  
	};

	void zatrudnij_marketera();
	void zatrudnij_robotnika();
	void zatrudnij_inzyniera();
	void zatrudnij_magazyniera();

	void wez_kredyt();
	void wypisz_pracownikow();
	void koniec_miesiaca();
		double splata_kredytu();
		double wzrost_wartosci();
	
		//potrzebne do Gry
	int get_mijajacy_miesiac();
	int get_cena_produktu();
	int get_popyt();
	int get_pojemnosc_magazynu();
	int get_teoretycznie_wyprod_produkt();
	int get_wynagrodzenie_laczne();
	int get_okres();
	int get_ilosc_pracownikow();
	int get_liczba_sprzedanych_produktow();
	double getWartosc_spolki();
	double getSumaRat();
	double getPrzychod();
	double get_czysty_zysk();
	double get_stan_konta();
	double wartosc_firmy();

protected:
	std::vector <Kredyt> wektor_kredytow;
	std::vector <double> historia_przychodow;
	std::vector <std::unique_ptr <Pracownik>> wektor_pracownikow;

	int cena_produktu;
	int popyt;
	int pojemnosc_magazynu;
	int teor_wyprodukowane_produkty;

	int wynagrodzenie_laczne;
	int liczba_sprzed_produktow;
	int okres = 12; //ilosc miesiecy, na pdstawie ktorych liczymy wartosc spolki
	int mijajacy_miesiac=0;
	double suma_rat;
	double przychod;
	double wartosc_spolki;
	double czysty_zysk;
	double stan_konta = 100;
};

#endif // !FIRMA_H
