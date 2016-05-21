// Dice header file

#include <string>
#include <iostream>
#include <vector>
#include <istream>
#include <random>

using namespace std;

class Dice
{
	 default_random_engine generator;
	public:
		int rollDice()
		{
			    uniform_int_distribution<int> distribution(1,6);
				int numberRolled = distribution(generator); 
				return numberRolled;
		}
};


