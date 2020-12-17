#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>
#include "Firma.h"
#include "Gra.h"

void Gra::granie()
{
	Firma firm;
	const double kapital_konczacy = 5000;
	const float mozliwe_zadluzenie_stala = 3.5;
	
	cout << " Musisz osiagnac wartosc firmy na poziomie " << kapital_konczacy << "zl, aby wygrac.\n Twoj kapital poczatkowy to 100zl." << endl;

	while (firm.getWartosc_spolki() < kapital_konczacy && firm.get_stan_konta() >= 0 && firm.getSumaRat() <= mozliwe_zadluzenie_stala * firm.getWartosc_spolki())
	{
		string k;
		cin >> k;
		if (k == "zatrInz")
		{
			firm.zatrudnij_inzyniera();
		}
		else if (k == "zatrMag")
		{
			firm.zatrudnij_magazyniera();
		}
		else if (k == "zatrRob")
		{
			firm.zatrudnij_robotnika();
		}
		else if (k == "zatrMark")
		{
			firm.zatrudnij_marketera();
		}
		else if (k == "bioreKredyt")
		{
			firm.wez_kredyt();
		}
		else if (k == "listPrac")
		{
			firm.wypisz_pracownikow();
		}
		else if (k == "koniecMies")
		{	
			cout << " Zakonczony miesiac " <<( firm.get_mijajacy_miesiac() +1)<< "." << endl;
			
			firm.koniec_miesiaca();

			cout << " Obecna cena produktu to " << firm.get_cena_produktu() << "zl, pojemnosc magazynu - " << firm.get_pojemnosc_magazynu() << ",\n liczba produkowanych produktow - " << firm.get_teoretycznie_wyprod_produkt() << ", a ilosc mozliwych do sprzedania produktow - " << firm.get_popyt() << "." << endl;
			cout << " W tym miesiacu suma wyplacanych wynagrodzen dla " << firm.get_ilosc_pracownikow() << " pracownikow wyniosla " << firm.get_wynagrodzenie_laczne() << "zl." << endl;
			cout << " Liczba faktycznie sprzedanych produktow - " << firm.get_liczba_sprzedanych_produktow() << "." << endl;
			cout << " W tym miesiacu suma rat splacanych kredytow wyniosla " << fixed << setprecision(2) << firm.getSumaRat() << "zl." << endl;
			cout << " W tym miesiacu czysty zysk wyniosl " << fixed << setprecision(2) << firm.get_czysty_zysk() << " zl." << endl;
			cout << " Stan konta Twojej firmy aktualnie wynosi " << firm.get_stan_konta() << "zl." << endl;
			cout << " Calkowita wartosc firmy wynosi " << fixed << setprecision(2) << firm.getWartosc_spolki() << " zl." << endl;

		}
		else
		{
			cout << "Nie ma takiej operacji mozliwej w grze, probuj dalej - wpisz poprawna komende." << endl;
		}
	}

	if (firm.get_stan_konta() < 0)
	{
		cout << "BANKRUT!!!! Niestety stan Twojego konta osiagnal ujemna wartosc - oznacza to koniec zabawy." << endl;
	}
	else if (firm.getSumaRat() >= (3 * firm.getWartosc_spolki()))
	{
		cout << "BANKRUT!!!! Niestety stan Twojego zadluzenia osiagnal wartosc " << mozliwe_zadluzenie_stala << " raz wieksza niz wartosc Twojej firmy - oznacza to koniec zabawy." << endl;
	}
	else if(firm.getWartosc_spolki()>kapital_konczacy)
	{
		cout << "Gra zakonczona sukcesem! Osiagnieto kapital "<<kapital_konczacy<<" zl!! Gratulacje! :) :) :)" << endl;
	}
}
