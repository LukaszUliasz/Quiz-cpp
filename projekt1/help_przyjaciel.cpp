#include "help_przyjaciel.h"
#include"help.h"
#include<fstream>
#include<string>
#include<cstdlib>
#include<iostream>
#include<time.h>

using namespace std;


help_przyjaciel::help_przyjaciel()
{
}
help_przyjaciel::~help_przyjaciel()
{
}

void help_przyjaciel::przyjaciel()
{
	fstream przyjaciel;
	przyjaciel.open("przyjaciel.txt", ios::in);
	if (przyjaciel.good() == false)
	{
		cout << "Nie odnaleziono pliku";
		exit(0);
	}

	srand(time(NULL));
	string linia;
	string wypowiedz;
	int nr_lini = rand() % 4 + 1;

	string tab_wyp[5];

	for (int i = 0; i < 5 ; i++)
	{

		getline(przyjaciel, linia);
		tab_wyp[i] = linia;
	}
	wypowiedz = tab_wyp[rand() % 4 + 1];

	cout << wypowiedz;

	przyjaciel.close();
}
