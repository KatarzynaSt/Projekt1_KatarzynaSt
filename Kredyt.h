#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

#ifndef KREDYT_H
#define KREDYT_H

using namespace std;

class Kredyt
{
public:
	Kredyt(double suma_kredytu, int miesiace) : suma_kredytu(suma_kredytu), miesiace(miesiace)
	{
		odsetki = 1.23456789 * miesiace;
		rata = (suma_kredytu/ miesiace)  + odsetki;
		pozostale_raty = miesiace;
		cout << " Wziales kredyt na sume " << suma_kredytu << "zl, a kredyt bedzie splacany przez "
			<< miesiace << " miesiecy. Za ten kredyt odsetki wynosza "<< fixed << setprecision(2)<<odsetki<<"zl. Miesieczna rata wynosi " << rata << "zl." << endl;
	};
double getRata();
int getMiesiace();
int get_pozostale_raty();
void splac_rate();
bool splacony();
	
private:
	int miesiace;
	int pozostale_raty=0;
	double odsetki;
	double rata;
	double suma_kredytu;
};

#endif // !KREDYT_H

