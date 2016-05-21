// Dice game header file

#include "Dice.h"
#include "Player.h"

#include <iostream>
#include <string>
using namespace std;

class DiceGame
{
	Dice dice;
	vector <Player> playerVector;
	vector <int> testVector;

	int playerTurn;
	bool isDone;
	
	void performTurn();
		
	public:
		DiceGame();
		void play();
		

};
