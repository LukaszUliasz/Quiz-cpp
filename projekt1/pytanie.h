#include<iostream>
#include<string>
#include "help_przyjaciel.h"
#include"help.h"
#pragma once

using namespace std;

class pytanie{

private:

	string tresc;
	string a, b, c, d;
	string poprawna;
	string odpowiedz;

public:

	int nr_pytania;

	void wczytaj(); // wczytuje pytanie z pliku
	void zadaj();  //zadaje pytanie
	void kolo_fifty(); //sprawdza kolo ratunkowe 50/50
	void kolo_przyjaciel();
	bool sprawdz(); //sprawdza poprawna odpowiedz
};
