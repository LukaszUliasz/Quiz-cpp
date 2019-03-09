#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdlib>
#include<time.h>
#include"pytanie.h"
#include"user.h"
#include "help_przyjaciel.h"
#include "help.h"


using namespace std;

int liczba;

int main()
{
	int tablica_wyniku[12] = { 0,1,2,4,8,16,32,64,128,256,512,1024};
	int suma=0; 
	pytanie p[12];
	user nazwa("user");  
	int* tablica = new int[12];
	int nr_pytania=0;

	cout << "\n********** Witaj W QUZIE WIEDZY **********\n" << endl;
	cout << "Podaj swoj nick aby rozpoczac quiz: ";
	nazwa.wczytaj();
	cout << "\n\tZasady gry:\n\tPrzed Toba 12 pytan na ktore musisz odpowedziec aby zdobyc 1024pkt\n";
	cout << "\tPosiadasz 2 kola ratunkowe( wspracie przyjaciela(friend) oraz pol na pol(50/50))\n";
	cout << "\tZa kazde kolejne poprawne odpowiedzi dostajesz punkty ktorych suma wynosi 1024 POWODZENIA :D " << endl << endl;
	
nowa_gra:

	for (int i = 0; i <= 11; i++) //generowanie pytania
	{
		cout << "***** PYTANIE NR: " << i+1 << " za " << tablica_wyniku[i + 1] << "pkt *****" << endl << endl;
		p[i].nr_pytania = i + 1;
		p[i].wczytaj();
		p[i].zadaj();
		p[i].kolo_fifty();
		p[i].kolo_przyjaciel();
		p[i].sprawdz();

			if (p[i].sprawdz() == true)
			{
				tablica[i] = 1;
				nr_pytania += tablica[i];
			}
			else{
			goto nowa_gra;}

		suma = (tablica_wyniku[i] * 2)/2 ;
	
		system("cls");
	}

	cout << "\nKoniec gry ***GRATULACJE*** " <<nazwa<< ". \nDoszedles do pytania nr: " <<nr_pytania;
	cout << " i uzyskales: " << suma << " pkt\n\n";

	delete[]tablica;
	system("pause");
	return 0;
}