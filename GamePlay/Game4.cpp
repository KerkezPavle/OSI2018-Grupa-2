#include "Game4.h"
#include <iostream>
#include <random>
#include <iomanip>

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

void Mineboard::draw_board(bool should_reveal)
{
	char LINE[41] = "----------------------------------------";
	std::cout << CLEAR << "   ";
	// drawing the board axis
	for (size_t j = 0; j < width; ++j)
		std::cout << std::setw(3) << j << ' ';
	std::cout << "\n";

	for (size_t i = 0; i < height; ++i) {
		std::cout << "   " << LINE << '\n'
			<< std::setw(2) << i << " |";
		for (size_t j = 0; j < width; ++j)
		{
			square_at(i, j).draw_square(should_reveal);
			std::cout << RESET << '|';
		}
		std::cout << "\n";
	}
	std::cout << "   " << LINE << '\n';
}

void Mineboard::uncover_square(int row, int col)
{
	if (index_in_range(row, col) && square_at(row, col).state == Square::State::Hidden && !square_at(row, col).has_mine())

	{
		squaresLeft--;
		int nearMinesCount = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				nearMinesCount += square_at(row + i, col + j).has_mine() ? 1 : 0;

		square_at(row, col).make_revealed();
		square_at(row, col).set_close_mines(nearMinesCount);


		if (!nearMinesCount) 
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
	return board[row][col];
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

void Mineboard::Square::set_close_mines(int count)
{
	 if (count == 0) closeMines = ' ' - 48; 
	 else closeMines = count; 
}

void Mineboard::Square::draw_square(bool should_reveal) const
{

	if (has_mine() && should_reveal)
		std::cout << RED << ' ' << '#' << ' ';
	else if (state == State::Revealed && !has_mine())
	{
		std::cout << GREEN << ' ' << (char)(closeMines+48) << ' ';
	}

	else
		std::cout << TILE << ' ' << '+' << ' ';



}
