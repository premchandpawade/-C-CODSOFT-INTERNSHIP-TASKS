//******************************number guessing game*************************


#include <iostream>
#include <cstdlib> 
#include <ctime> 

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void guessAnswer(int answer)
{
	for (int attempt = 1; attempt <= 7; ++attempt)
	{
		std::cout << "Guess #" << attempt << ": ";
		int guess;
		std::cin >> guess;
		std::cin.ignore(32767, '\n');

		while (std::cin.fail() || guess < 1 || guess > 100)
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cerr << "That is not a number. Enter again: ";
			} else 
				std::cerr << "Please enter a number between 1 and 100: ";

			std::cin >> guess;
			std::cin.ignore(32767, '\n');
		}

		if (guess < answer)
			std::cout << "Your guess is too low.\n";
		else if (guess > answer)
			std::cout << "Your guess is too high.\n";
		else
		{
			std::cout << "Correct! You win!\n";
			break;
		}
		if (attempt == 7)
			std::cout << "Sorry, you lose. The answer was " << answer << '\n';
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); 
	rand();
	char playAgain = 'y';

	do
	{
		int answer = getRandomNumber(1,100);
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		guessAnswer(answer);

		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> playAgain;
		std::cin.ignore(32767, '\n');

		while (std::cin.fail() || (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N'))
		{
			if (std::cin.fail()) 
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cerr << "That is not a character. Enter again: ";
			} else
				std::cerr << "Please enter \"y\" or \"n\": ";

			std::cin >> playAgain;
			std::cin.ignore(32767, '\n');
		}
	}
	while (playAgain == 'y' || playAgain == 'Y');

	std::cout << "Thank you for playing.\n";
	return 0;
}
