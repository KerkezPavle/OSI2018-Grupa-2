#include "Game4.h"
#include <iostream>
#include <random>

Mineboard::Mineboard()
{

	int x, y;

	for (int minesPut = 0; minesPut < MINENUM; minesPut++)
	{
		do // checking to see if a square already has a mine
		{

			x = rand() % width;
			y = rand() % height;


		} while (square_at(x, y).has_mine());

		square_at(x, y).put_mine(); //if it doesn't, placing a mine
	}

}

Mineboard::~Mineboard()
{
}

void Mineboard::uncover_square(int row, int col)
{
	if (index_in_range(row, col) && square_at(row, col).state == Square::State::Hidden)

	{
		squaresLeft--;
		int nearMinesCount = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				nearMinesCount += square_at(row + i, col + j).has_mine() ? 1 : 0;
		square_at(row, col).set_revealed_state(nearMinesCount);

		if (nearMinesCount) 
		{
			uncover_square(row - 1, col);
			uncover_square(row, col - 1);
			uncover_square(row + 1, col);
			uncover_square(row, col + 1);
		}
	}
	
}


Mineboard::Square& Mineboard::square_at(int row, int col)
{
	return board[width *row + col];
}

bool Mineboard::index_in_range(int row, int col)
{
	if (row >= 0 && col >= 0 && row < height  &&  col < width) //if the index input is in range
		return true;
	else
	{
		std::cout << "\nError: please enter a number in range.\n";
		return false;
	}
}

void Mineboard::Square::set_revealed_state(int count)
{
	 if (count == 0) revealedState = ' '; 
	 else revealedState = count + 48; 
}
