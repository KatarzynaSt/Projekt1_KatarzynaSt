#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>
#include "Gra.h"

using namespace std;
int main()
{
    cout << " Oto moja gra, milej zabawy! :) \n";

    cout << " W grze mozesz (podane odpowiednie komendy): \n - zatrudnic: inzyniera - zatrInz,\n\t      magazyniera - zatrMag, \n\t      marketera - zatrMark, \n \t      robotnika - zatrRob, \n";
    cout << " - wyswietlic liste pracownikow wraz z ich umiejetnosciami - listPrac,\n - wziac kredyt - bioreKredyt.\n\n";
    cout << " W grze mozesz rowniez zakonczyc miesiac - koniecMies. Wtedy oplaczasz odsetki, placisz wynagrodzenia pracownikom \n i przede wszystkim sprzedajesz towar. Niesprzedany towar w danym miesiacu marnuje sie." <<endl;
    
    Gra T; 
    T.granie();

    cout << "\nKoniec gry - jesli masz ochote zagraj jeszcze raz :) \n";
    cout << "Made by Katarzyna Steczniewska" << endl;

    system("pause > 0");
}
