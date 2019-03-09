#include <iostream>
#include "user.h"
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std; 


void user::wczytaj()
{
	cin >> nick;

}
ostream& operator<<(ostream & wyjscie, const user & n)
{
	return wyjscie << n.nick;
}

user::user(string n)
{
	nick = "user";
}

user::~user()
{
}


