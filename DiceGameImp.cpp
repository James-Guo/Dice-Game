// Dice Game Imp file

#include "DiceGame.h"

#include <stdio.h>

using namespace std;


DiceGame::DiceGame()
{
	
	playerTurn = 0;
	isDone = false;

	// intialise players
	int numberOfPlayers;
	printf("Enter the number of players: ");
	cin >> numberOfPlayers;

	
	
	for (int i = 0; i < numberOfPlayers; i++)
	{	
		string pName;
		
		printf( "Enter the name of player %d: ",  i + 1 );
		cin >> pName;
				
		playerVector.push_back(Player(pName) );
	}
	
	printf("\nYou are ready to begin to game\n\n");
}

void DiceGame::performTurn()
{
	char answer;
	int sumOfScoreForTurn = 0;

	printf("%s\n", string(80, '-').c_str());
	printf("\nIt is %s's turn!\n", playerVector[playerTurn].name.c_str());
	
	do 
	{
		// roll
		int currentRoll = dice.rollDice();

		printf("%s rolled a %i\n", playerVector[playerTurn].name.c_str(), currentRoll);
		
		
		// if 1 exit
		if (currentRoll == 1)
		{
			printf("\nSorry your turn has ended\n");
			break;
		}
		
		// choose if you want to keep rolling
		else
		{
			sumOfScoreForTurn += currentRoll;

			// check if game ends
			if ( ( playerVector[playerTurn].points + sumOfScoreForTurn )>= 100)
			{
				printf("%s\n", string(50, '\n').c_str());
				printf("Congratulations %s you have won!\m", playerVector[playerTurn].name.c_str());
				isDone = true;
				break;
			}

			do
			{
				printf("Total score this turn: %i\n", sumOfScoreForTurn);
				
				printf("Total score: %i\n", playerVector[playerTurn].points);
				
				printf("Continue? (Y/N): ");
				cin >> answer;
			} while ( !(answer == 'y' || answer == 'Y' || answer == 'N' || answer == 'n'));

			if (answer == 'N' || answer == 'n') 
				playerVector[playerTurn].points += sumOfScoreForTurn;
			
		}
		
	
	} while (answer == 'Y' || answer == 'y');
	
	
	
}



void DiceGame::play()
{
	// game loop
	while ( isDone == false)
	{
		performTurn();	

		printf("%s", string(40, '\n').c_str());
		printf("%s\n", string(80, '*').c_str());

		// print out all the players scores
		for (int i = 0; i < playerVector.size(); i++)
			printf("%s is currently on %d points\n", playerVector[i].name.c_str(),  playerVector[i].points);

		printf("%s\n", string(80, '*').c_str());

		// increment the players turns
		if (playerTurn + 1 < playerVector.size() )
			playerTurn++;
		else
			playerTurn = 0;
	
	}
}




