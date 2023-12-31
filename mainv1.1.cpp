#include <iostream>

/* Computer value(rock, paper, or scissors)
*  User value(rock, paper, or scissors)
*  Compare the two
*/

/* Added a while loop to give the option to keep playing
   Added better formatting to appear more readable in console*/

char comVal()
{
	char c;
	srand(time(0));
	int num = { rand() % 3 + 1 }; // Random int between 1 and 3

	if (num == 1) 
	{
		c = 'r';
	}
	else if (num == 2)
	{
		c = 'p';
	}
	else if (num == 3)
	{
		c = 's';
	}

	return c;
}

char playerVal()
{
	char c;
	std::cout << "\nPlease Input Your Selection: " << std::endl;
	std::cout << "Rock('r') - Paper('p') - Scissors('s')" << std::endl;
	std::cin >> c;
	std::cout << std::endl;

	return c;
}

int compareVal(char x, char y)
{
	if (x == 'r' && y == 's') // If player wins
	{
		return 1;
	}
	else if (x == 'p' && y == 'r')
	{
		return 2;
	}
	else if (x == 's' && y == 'p')
	{
		return 3;
	}
	else if (x == 'p' && y == 's') // If computer wins
	{
		return 4;
	}
	else if (x == 's' && y == 'r')
	{
		return 5;
	}
	else if (x == 'r' && y == 'p')
	{
		return 6;
	}
	else if (x == y) // Player and Computer Tie
	{
		return 7;
	}
}

void endGame(int x)
{
	if (x == 1 || x == 2 || x == 3)
	{
		std::cout << "You Win!" << std::endl;
	}
	else if (x == 4 || x == 5 || x == 6)
	{
		std::cout << "You Lose." << std::endl;
	}
	else if (x == 7)
	{
		std::cout << "It is a tie!" << std::endl;
	}
}

int main()
{
	bool gameOver = true;
	char playAgain;

	std::cout << "Welcome to a friendly game of Rock-Paper-Scissors!" << std::endl;
	std::cout << "The rules are simple: You will be picking rock, paper, or scissors against the computer." << std::endl;
	std::cout << "Rock beats Scissors - Paper beats Rock - Scissors beats Paper." << std::endl;
	std::cout << "Good Luck!" << std::endl;

	while (gameOver)
	{

		char player = playerVal();
		char computer = comVal();

		int winner = compareVal(player, computer);

		endGame(winner);
		std::cout << "\nWould you like to play again?(y/n)? " << std::endl;
		std::cin >> playAgain;

		if (playAgain == 'n')
		{
			gameOver = false;
		}
		else
		{
			gameOver = true;
		}
	}
}
