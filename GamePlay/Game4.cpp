
#include "Game4.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <string>


void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}


void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

Mineboard::Mineboard(int width, int height) :width(width), height(height)
{
	board = allocate(width, height);
	int x, y;

	for (int minesPut = 0; minesPut < (width*height) / 6; minesPut++)
	{
		do // provjera da li vec na toj plocici (kvadraticu) postoji mina
		{

			x = rand() % width;
			y = rand() % height;


		} while (square_at(x, y).has_mine());

		square_at(x, y).put_mine(); // ako ne postoji, postavlja se
	}

}

Mineboard::Mineboard(int width, int height, bool) :width(width), height(height)
{
	board = allocate(width, height);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			square_at(i, j).isMine = false;
}

Mineboard::~Mineboard()
{

	/*for (int i = 0; i < width; i++)
		delete[] board[i];
	delete board;*/

}

void Mineboard::draw_board(bool should_reveal)
{
	static const std::string line(4 * width, '-');

	if (width*height != how_many_left())
		ClearScreen();
	// crtaju se ose i njihove labele na ekranu
	std::cout << "   ";
	for (int j = 0; j < width; ++j)
		std::cout << std::setw(3) << j << ' ';
	std::cout << "\n";

	for (int i = 0; i < height; ++i) {
		std::cout << "   " << line << '\n'
			<< std::setw(2) << i << " |";
		for (int j = 0; j < width; ++j)
		{
			square_at(i, j).draw_square(should_reveal);
			std::cout << '|';
		}
		std::cout << "\n";
	}
	std::cout << "   " << line << '\n';
}

void Mineboard::uncover_square(int row, int col)
{
	if (index_in_range(row, col, this->width, this->height) && square_at(row, col).state == Square::State::Hidden && !square_at(row, col).has_mine())

	{
		squaresLeft--;
		int nearMinesCount = count_close_mines(row, col);


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
	return board[col][row];
}

Mineboard::Square** Mineboard::allocate(int width, int height)
{
	Square** array = new Square*[width];
	for (int i = 0; i < width; i++)
		array[i] = new Square[height];
	return array;
}

bool Mineboard::index_in_range(int row, int col, int width, int height)
{
	if (row >= 0 && col >= 0 && row < height  &&  col < width) //provjerava se da li je indeks u opsegu
		return true;
	else
	{
		//std::cout << "\nError: please enter a number in range.\n";
		return false;
	}
}

void Mineboard::place_mines(int row, int col, int numberOfMines)
{
	if (!square_at(row, col).has_mine())
	{
		square_at(row, col).put_mine();
		numberOfMines--;
	}
	for (int i = 0; i < height; i++) //dodavanje mina da se zadovolje jedinice koje su prikazane korisniku
	{
		for (int j = 0; j < width; j++)
		{
			Square& currSquare = square_at(i, j);
			if (currSquare.closeMines == 1 && count_close_mines(i, j) != 1)
			{
				for (int k = -1; k < 2 && count_close_mines(i, j) != 1; k++)
					for (int l = -1; l < 2 && count_close_mines(i, j) != 1; l++)
					{

						if (index_in_range(i + k, l + j, this->width, this->height)) // provjera da li je index u opsegu tj da li postoji ta plocica na tabli
						{
							if (k == l && k == 0) {}
							else
								// provjerava da li je u okolini vec drugi broj na koji bi to moglo uticati
								if (!square_at(i + k, l + j).is_revealed())
									if (count_hidden(i + k, j + l) > 6)
									{
										square_at(k + i, l + j).put_mine();
										numberOfMines--;
									}
						}
					}
			}

		}
	}

	int x, y;

	for (int minesPut = 0; minesPut < numberOfMines; minesPut++) //dodavanje ostatka mina nasumicno pri cuvanju poretka na tabli
	{
		do // provjera da li vec na toj plocici (kvadraticu) postoji mina i da li je sakriveno sa svih strana
		{

			x = rand() % height;
			y = rand() % width;


		} while (square_at(x, y).has_mine() || !surrounded_by_hidden(x, y) || square_at(x, y).state == Mineboard::Square::State::Revealed);

		square_at(x, y).put_mine(); // ako zadovoljava uslove, postavlja se
	}



}

bool Mineboard::are_neighbours(int row1, int col1, int row2, int col2)
{
	Square& square1 = square_at(row1, col1);
	Square& square2 = square_at(row2, col2);

	if (row1 - row2 <= 1 && row1 - row2 >= -1) // provjeravamo da li su im redovi susjedni
		if (col1 - col2 <= 1 && col1 - col2 >= -1) //provjeravamo da li su kolone susjedne, ako jeste oboje, i polja su susjedna
		{
			if (row1 == row2)// ako su u istom redu
			{
				if (row1 + 1 < height)//ako se moze dodati iznad,tj ako nije red krajnji donji
				{
					square_at(row1 + 1, col1).put_mine(); return true; //dodajemo ispod prvog polja
				}
				else
				{
					square_at(row1 - 1, col1).put_mine(); return true; //dodajemo iznad prvog polja
				}

			}

			if (col1 == col2)// ako su u istoj koloni
			{
				if (col1 + 1 < width)//ako se moze dodati desno,tj ako nije red krajnji desni
				{
					square_at(row1, col1 + 1).put_mine(); return true; //dodajemo desno od prvog polja
				}
				else
				{
					square_at(row1, col1 - 1).put_mine(); return true; //dodajemo lijevo od prvog polja
				}

			}

			else
			{
				if (col2 > col1)
				{
					square_at(row1, col2).put_mine();// ako su dijagonalno dodamo na desno mjesto,gornje ili donje zavisi od polozaja;
					return true;
				}
				else
				{
					square_at(row2, col1).put_mine();
					return true;
				}
			}
		}
		else
			return false;
	return false;
}

void Mineboard::Square::set_close_mines(int count)
{
	if (count == 0) closeMines = ' ' - 48;
	else closeMines = count;
}

int Mineboard::count_close_mines(int row, int col)
{
	int nearMinesCount = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if (index_in_range(row + i, col + j, this->width, this->height))
				nearMinesCount += square_at(row + i, col + j).has_mine() ? 1 : 0;
		}
	return nearMinesCount;
}

bool Mineboard::surrounded_by_hidden(int row, int col)
{
	bool isHidden = true;

	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{

			if (index_in_range(row + i, col + j, this->width, this->height)) // provjera da li je index u opsegu tj da li postoji ta plocica na tabli
			{
				if (square_at(row + i, col + j).state == Mineboard::Square::State::Revealed) // ako plocica nije otkrivena ona ne predstavlja problem pri ubacivanju mine
				{
					isHidden = false;
				}
			}
		}
	return isHidden;

}

void calculate_dimension(int pointsToLose, int& numberOfMines, int& width, int& height)
{
	//points to lose+ numberofmines+ 1 = dimesion*dimension
	int i;
	for (i = pointsToLose; sqrt(float(i)) - (int)sqrt(i) > 0.0000001; i++);
	int dimension = sqrt(i);
	numberOfMines = dimension * dimension - pointsToLose - 1;
	width = dimension;
	height = dimension;
	while (numberOfMines < (dimension*dimension / 6))
	{
		width++;
		numberOfMines += height;
	}
	return;


}

void Mineboard::Square::draw_square(bool should_reveal) const
{

	if (has_mine() && should_reveal)
	{
		setcolor(16 * 0 + 12);
		std::cout << ' ' << '#' << ' ';
		setcolor(16 * 0 + 7);
	}

	else if (state == State::Revealed && !has_mine())
	{
		setcolor(10);
		std::cout << ' ' << (char)(closeMines + 48) << ' ';
		setcolor(7);
	}

	else
	{
		setcolor(16 * 7 + 0);
		std::cout << ' ' << '+' << ' ';
		setcolor(7);
	}



}

int Mineboard::count_hidden(int row, int col)
{

	int count = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{


			if (index_in_range(row + i, col + j, this->width, this->height)) // provjera da li je index u opsegu tj da li postoji ta plocica na tabli
			{
				if (square_at(row + i, col + j).state == Mineboard::Square::State::Hidden)
				{
					if (i == j && i == 0) {}
					else
						count++;
				}
			}
			else count++;
		}
	return count;


}


int Game4(int points, int percentToLose)
{
	{
		int pointsToLose = ((points * percentToLose) / 100);

		if (percentToLose == 0)// ako nema potrebe za gubitkom poena igrac igra igru neometano
		{
			Mineboard board(STANDARDSIZE, STANDARDSIZE);
			board.draw_board(false);
			bool loss = false; // sadrzi info da li je igrac izgubio
			std::cout << std::endl << "Dobrodosli! Igracete igru na tabli velicine " << STANDARDSIZE << "x" << STANDARDSIZE << " koja sadrzi " << (STANDARDSIZE*STANDARDSIZE) / 6 << " sakrivenih mina. Srecno! \n" << std::endl;

			for (loss; !(board.how_many_left() == (board.get_width()* (board.get_height())) / 6) && !loss; board.draw_board(loss))
			{

				int row;
				int  col;

				do
				{
					std::cout << "Unesite red i kolonu: ";

					std::cin >> row >> col;

				} while (!Mineboard::index_in_range(row, col, board.get_width(), board.get_height()) || board.square_at(row, col).is_revealed());


				if (Mineboard::index_in_range(row, col, board.get_width(), board.get_height()))

				{
					loss = board.square_at(row, col).has_mine();
					if (!loss)
					{
						board.uncover_square(row, col);
					}
				}
			}
			if (board.how_many_left() == (board.get_width()*board.get_height() / 6))
			{
				std::cout << "Cestitamo! Osvojili ste 100 poena!\n";
				return points + 100; //ako pobijedi dodaje mu se sto poena na trenutno stanje
			}
			else
			{                                                          // izracunavanje broja cistih polja
				std::cout << "Ups! Stali ste na minu. Izgubili ste " << board.how_many_left()-(STANDARDSIZE*STANDARDSIZE)/6 << " poena. Vise srece drugi put! \n";
				return points + (board.how_many_left() - (STANDARDSIZE*STANDARDSIZE) / 6); // od trenutnog broja poena oduzima se broj preostalih cisth polja
			}


		}
		else
		{

			int width, height, numberOfMines;
			calculate_dimension(pointsToLose, numberOfMines, width, height); //preracunavaju se dimenzije tabele najpogodnije za zeljeni rezultat

			Mineboard board(width, height, true);
			board.draw_board(true);
			std::cout << std::endl << "Dobrodosli! Igracete igru na tabli velicine " << width << "x" << height << " koja sadrzi " << numberOfMines << " sakrivenih mina. Srecno! \n" << std::endl;


			int row;
			int  col;

			// prividno normalno igranje igre i izbor polja

			do
			{
				std::cout << "Unesite red i kolonu: ";

				std::cin >> row >> col;

			} while (!Mineboard::index_in_range(row, col, board.get_width(), board.get_height()) || board.square_at(row, col).is_revealed());

			board.squaresLeft--;
			board.square_at(row, col).set_close_mines(1); board.square_at(row, col).make_revealed();
			board.draw_board(false);


			do
			{
				std::cout << "Unesite red i kolonu: ";

				std::cin >> row >> col;

			} while (!Mineboard::index_in_range(row, col, board.get_width(), board.get_height()) || board.square_at(row, col).is_revealed());


			board.squaresLeft--;
			board.place_mines(row, col, numberOfMines); //popunjavanje minama u skladu sa dosadasnjim prikazanim stanjem
			board.draw_board(true);
			std::cout << "Ups! Stali ste na minu. Izgubili ste " << width * height - numberOfMines - 1 << " poena. Vise srece drugi put! \n";
			return points + pointsToLose;

		}
	}

}
