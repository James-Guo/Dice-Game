// Player header file

#include <string>
#include <iostream>
using namespace std;

struct Player
{		
	Player(string n)
	{
		points = 0;
		name = n;
	}
		
	int points;
	string name;	

};
