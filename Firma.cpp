#include <iostream>
#include <istream>
#include <math.h>
#include "RandomNameGenerator.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <iterator>
#include <list>
#include <ctime>
#include <iomanip>
#include <random>
#include <time.h>
#include "Firma.h"
#include "Pracownik.h"
#include "Inzynier.h"
#include "Magazynier.h"
#include "Marketer.h"
#include "Robotnik.h"
#include "Kredyt.h"

void Firma::zatrudnij_marketera() 
{
	wektor_pracownikow.emplace_back(std::make_unique<Marketer>(rand() % 90 + 11, get_random_name()));
}

void Firma::zatrudnij_robotnika()
{
	wektor_pracownikow.emplace_back(std::make_unique<Robotnik>(rand() % 9 + 36, get_random_name()));
}

void Firma::zatrudnij_inzyniera()
{
	wektor_pracownikow.emplace_back(std::make_unique<Inzynier>(rand() % 3 + 1, get_random_name()));
}

void Firma::zatrudnij_magazyniera()
{
	wektor_pracownikow.emplace_back(std::make_unique<Magazynier>(rand() % 3 + 1, get_random_name()));
}

void Firma::wypisz_pracownikow()
{
	cout << " Twoja firma zatrudnia "<<wektor_pracownikow.size()<<" pracownikow." << endl;
	for (int i = 0; i < wektor_pracownikow.size(); i++)
	{
		wektor_pracownikow[i]->drukuj_osobe();
	}
}

void Firma::wez_kredyt()
{
	int miesiace;
	double suma_kredytu;
	cout << " Na jaka kwote chcesz wziac kredyt?" << endl;
	cin >> suma_kredytu;
	if (cin.bad())
		{
		cin.clear();
		cout <<  " Musi byc liczba!!" << endl;
		cin >> suma_kredytu;
	}
	cout << " W ilu ratach (ilosc miesiecy) chcesz splacic kredyt?" << endl;
	cin >> miesiace;
	while (cin.bad())
		{
		cout << " Musi byc liczba calkowita!!" << endl;
		cin.clear();
		cin >> miesiace;
	}

	wektor_kredytow.emplace_back(suma_kredytu, miesiace);
	stan_konta = stan_konta + suma_kredytu;
}

double Firma::splata_kredytu()
{
	suma_rat = 0;
	for (auto it = wektor_kredytow.begin(); it != wektor_kredytow.end();) {
		double rata;
		it->splac_rate();
		rata = it->getRata();
		if (it->splacony()){}
		else
		{
			suma_rat = suma_rat + rata;
		}
		it++; 
	}
	return suma_rat;
}

double Firma::wzrost_wartosci()
{
	wynagrodzenie_laczne=0;
	cena_produktu = 0;
	popyt = 0;
	pojemnosc_magazynu = 0;
	teor_wyprodukowane_produkty = 0;
	for (int i =0 ; i<wektor_pracownikow.size(); i++)
	{
	cena_produktu = cena_produktu + wektor_pracownikow[i]->get_wzrost_ceny_produktu();
	popyt = popyt + wektor_pracownikow[i]->get_popyt();
	pojemnosc_magazynu = pojemnosc_magazynu + wektor_pracownikow[i]->get_PojemoscMagazynu();
	teor_wyprodukowane_produkty = teor_wyprodukowane_produkty + wektor_pracownikow[i]->get_teorWypr_produkty();
	wynagrodzenie_laczne = wynagrodzenie_laczne + wektor_pracownikow[i]->getWynagrodzenie();
	}
	//return cena_produktu;
//	return popyt;
	//return pojemnosc_magazynu;
//	return teor_wyprodukowane_produkty;
	return wynagrodzenie_laczne;
}

double Firma::wartosc_firmy()
{
	double suma_przychodow_w_ostanim_okresie=0;
	wartosc_spolki=0;
	if (mijajacy_miesiac>(okres-1))
	{ 
	for (int i=mijajacy_miesiac-okres; i< mijajacy_miesiac;i++) 
		{
			suma_przychodow_w_ostanim_okresie = suma_przychodow_w_ostanim_okresie + historia_przychodow[i];
		}	
	}
	wartosc_spolki = (suma_przychodow_w_ostanim_okresie / okres);
	return wartosc_spolki;
}

void Firma::koniec_miesiaca()
{
	mijajacy_miesiac++;
	wzrost_wartosci();

	splata_kredytu();

	double faktycznie_wyprod=0;
	if (get_pojemnosc_magazynu()<get_teoretycznie_wyprod_produkt())
		{
			faktycznie_wyprod = pojemnosc_magazynu;
		}
	else { 
		faktycznie_wyprod = teor_wyprodukowane_produkty; 
		 }

	liczba_sprzed_produktow = 0;
	if (get_popyt() > faktycznie_wyprod)
		{
		liczba_sprzed_produktow = faktycznie_wyprod;
		}
	else { liczba_sprzed_produktow = popyt; }

	przychod = liczba_sprzed_produktow * cena_produktu;
	historia_przychodow.push_back(przychod);
	
	double zysk=0;
	zysk = przychod - wynagrodzenie_laczne;
	czysty_zysk= zysk - suma_rat;
	stan_konta = stan_konta + czysty_zysk;

	if (mijajacy_miesiac > (okres - 1))
	{
		wartosc_firmy();
	}
	else {
		wartosc_spolki = wartosc_spolki * (mijajacy_miesiac-1);
		wartosc_spolki = wartosc_spolki + przychod;
		wartosc_spolki = wartosc_spolki / mijajacy_miesiac;
	}
}


int Firma::get_mijajacy_miesiac()
{
	return mijajacy_miesiac;
}

int Firma::get_cena_produktu()
{
	return cena_produktu;
}

int Firma::get_popyt()
{
	return popyt;
}

int Firma::get_pojemnosc_magazynu()
{
	return pojemnosc_magazynu;
}

int Firma::get_teoretycznie_wyprod_produkt()
{
	return teor_wyprodukowane_produkty;
}

int Firma::get_wynagrodzenie_laczne()
{
	return wynagrodzenie_laczne;
}

int Firma::get_okres()
{
	return okres;
}

int Firma::get_ilosc_pracownikow()
{
	return wektor_pracownikow.size();
}

int Firma::get_liczba_sprzedanych_produktow()
{
	return liczba_sprzed_produktow;
}

double Firma::getWartosc_spolki()
{
	return wartosc_spolki;
}

double Firma::getSumaRat()
{
	return suma_rat;
}

double Firma::get_czysty_zysk()
{
	return czysty_zysk;
}

double Firma::get_stan_konta()
{
	return stan_konta;
}

double Firma::getPrzychod()
{
	return przychod;
}