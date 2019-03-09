#include<iostream>
#include<string>

using namespace std;
class user
{
private:

	string nick;

public:
	
	user(string n);
	~user();
	void wczytaj();
	friend ostream& operator<<(ostream & wyjscie, const user & n);
};
