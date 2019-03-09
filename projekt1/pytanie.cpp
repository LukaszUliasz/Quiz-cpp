#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<windows.h>
#include "pytanie.h"
#include "help_przyjaciel.h"
#include"help.h"

using namespace std;


void pytanie::wczytaj()  //funkcja wczytujaca pytanie
{		
	fstream plik;
	plik.open("quiz.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie odnaleziono pliku";
		exit(0);
	}
		int nr_linii = (nr_pytania - 1) * 6 + 1;
		int aktualny_numer = 1;
		string linia;

		while (getline(plik, linia))
		{
			if (aktualny_numer == nr_linii) tresc = linia;
			if (aktualny_numer == nr_linii+1) a = linia;
			if (aktualny_numer == nr_linii+2) b = linia;
			if (aktualny_numer == nr_linii+3) c = linia;
			if (aktualny_numer == nr_linii+4) d = linia;
			if (aktualny_numer == nr_linii+5) poprawna = linia;
			aktualny_numer++;

		}
		plik.close();

}

void pytanie::zadaj()  // funkcja zadajaca pytanie
{
	cout << tresc << endl;
	cout <<"a) " << a << endl;
	cout <<"b) " << b << endl;
	cout <<"c) " << c << endl;
	cout <<"d) " << d << endl;
	cout <<"_______________"<< endl;
	cout << "odpowiedz: ";
	cin >> odpowiedz;
	
}

void pytanie::kolo_fifty()
{
	if (odpowiedz == "50/50")
		{
			cout <<"Wybierz poprawna odpowiedz \n" << poprawna << ")	lub	";
			cout << "b)\n"; // przyj¹³em ¿e odp b nie bedzie nigdy poprawna w ¿adnym pytaniu 
			cin >> odpowiedz;
		}
}

void pytanie::kolo_przyjaciel()
{
	help_przyjaciel wypowiedz;
	transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);
	if (odpowiedz == "friend")
	{
		wypowiedz.przyjaciel();
		cout <<"	"<< poprawna << ")"<<endl;
		cin >> odpowiedz;
	}
}
bool pytanie::sprawdz() // sprawdzenie poprawnoej odp
{
	string odp;
	transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(),::tolower);

	if (odpowiedz == poprawna)
	{
		return true;
	}
	else
	{
		cout << "Bledna odpowedz. Czy chcesz sprobowac jeszcze raz?  TAK/NIE" << endl;
		cin >> odp;
		
		transform(odp.begin(), odp.end(), odp.begin(), ::tolower);
		
			if (odp == "tak")
			{
				system("cls");
				return false; //else wykona siê 2 razy
			
			}
			else
			{
				cout << " KONIEC QUIZU\n Powodzenia nastepnym razem :D";
				Sleep(4000);
				exit(0);
			}
	}

}