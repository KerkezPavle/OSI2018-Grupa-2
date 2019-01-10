
#include "Game4.h"
#include <Windows.h>
#include <random>
#include <iomanip>
#include <string>
#include <ctime>


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
			srand(time(0));
			x = rand() % width;
			y = rand() % height;


		} while (square_at(x, y).has_mine());

		square_at(x, y).put_mine(); // ako ne postoji, postavlja se
	}

}

Mineboard::Mineboard(int width, int height, bool) :width(width), height(height)
{
	board = allocate(width, height);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			square_at(i, j).isMine = false;
}

Mineboard::~Mineboard()
{

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
	return board[row][col];
}

std::vector<std::vector<Mineboard::Square>> Mineboard::allocate(int width, int height)
{
	std::vector<std::vector<Square>> matrix(height, std::vector<Square>(width));
	return matrix;
}

bool Mineboard::index_in_range(int row, int col, int width, int height)
{
	if (row >= 0 && col >= 0 && row < height &&  col < width) //provjerava se da li je indeks u opsegu
		return true;
	else
	return false;
	
}

void Mineboard::place_mines(int row, int col, int numberOfMines)
{
	if (!square_at(row, col).has_mine())
	{
		square_at(row, col).put_mine();
		numberOfMines--;
	}
	for (int i = 0; i < height; i++) //dodavanje mina da se zadovolji podatak koji je prikazan korisniku
	{
		for (int j = 0; j < width; j++)
		{
			Square& currSquare = square_at(i, j);
			if (currSquare.closeMines != '/' && !count_matches_mines(i, j)) // ako trenutno polje ima neki broj kao vrijednost i ako taj broj ne odgovara dosadasnjem stanju na tabli dodaju se mine oko datog polja
			{
				for (int k = -1; k < 2 && !count_matches_mines(i, j); k++)
					for (int l = -1; l < 2 && count_matches_mines(i, j) != 1; l++)
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



bool Mineboard::count_matches_mines(int row, int col)
{
	Square& currSquare = square_at(row, col);
	if (count_close_mines(row, col) == 0)
		return currSquare.closeMines == ' ' - 48;
	else return count_close_mines(row, col) == currSquare.closeMines;

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

			if (index_in_range(row + i, col + j, this->width, this->height)) // provjera da li je index u opsegu tj da li postoji ta plocica na tabli, ako ne postoji ne ugrozava sakrivenost trenutne plocice
			{
				if (square_at(row + i, col + j).state == Mineboard::Square::State::Revealed) // ako je susjedna plocica otkrivena onda trenutna nije okruzena sakrivenim
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

		if (pointsToLose < 5) // da tabla ne bi bila previse mala
			pointsToLose = 5;

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
					try {
						std::string input;
						std::cout << "Unesite red:";
						std::getline(std::cin, input);
						row = std::stoi(input);
						std::cout << "Unesite kolonu:";
						std::getline(std::cin, input);
						col = std::stoi(input);
					}
					catch (std::invalid_argument ex) {
						std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
						row = col = -1;
					}
					catch (std::out_of_range ex) {
						std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
						row = col = -1;
					}
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
				std::cout << "Ups! Stali ste na minu. Izgubili ste " << board.how_many_left() - (STANDARDSIZE*STANDARDSIZE) / 6 << " poena. Vise srece drugi put! \n";
				return points - (board.how_many_left() - (STANDARDSIZE*STANDARDSIZE) / 6); // od trenutnog broja poena oduzima se broj preostalih cisth polja
			}
		}
		else
		{
			int width, height, numberOfMines;
			calculate_dimension(pointsToLose, numberOfMines, width, height); //preracunavaju se dimenzije tabele najpogodnije za zeljeni rezultat

			Mineboard board(width, height, true);
			board.draw_board(true);
			std::cout << std::endl << "Dobrodosli! Igracete igru na tabli velicine " << width << "x" << height << " koja sadrzi " << numberOfMines << " sakrivenih mina. Srecno! \n" << std::endl;

			int row, col;
			// prividno normalno igranje igre i izbor polja
			do
			{
				try {
					std::string input;
					std::cout << "Unesite red:";
					std::getline(std::cin, input);
					row = std::stoi(input);
					std::cout << "Unesite kolonu:";
					std::getline(std::cin, input);
					col = std::stoi(input);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
					row = col = -1;
				}
				catch (std::out_of_range ex) {
					std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
					row = col = -1;
				}

			} while (!Mineboard::index_in_range(row, col, board.get_width(), board.get_height()) || board.square_at(row, col).is_revealed());
			board.squaresLeft--;

			if (pointsToLose < 7 && row == 1 && col == 1)
				board.square_at(row, col).set_close_mines(width*height - pointsToLose - 1);
			else
			{
				srand(time(NULL));
				int random = rand() % 4 + 1;
				int edge = 0; // provjera na koliko ivica se nalazi izabrano polje (npr. u cosku table :2 ivice)
				edge += Mineboard::index_in_range(row - 1, col, width, height);
				edge += Mineboard::index_in_range(row + 1, col, width, height);
				edge += Mineboard::index_in_range(row, col - 1, width, height);
				edge += Mineboard::index_in_range(row, col + 1, width, height);

				if (edge == 2 && random > 3)
					random = 3;

				if (random > numberOfMines - 1)
					random = numberOfMines - 1;

				board.square_at(row, col).set_close_mines(random);
			}
			board.square_at(row, col).make_revealed();
			board.draw_board(false);
			do
			{
				try {
					std::string input;
					std::cout << "Unesite red:";
					std::getline(std::cin, input);
					row = std::stoi(input);
					std::cout << "Unesite kolonu:";
					std::getline(std::cin, input);
					col = std::stoi(input);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
					row = col = -1;
				}
				catch (std::out_of_range ex) {
					std::cout << "Na ulazu mora biti broj! Pokusajte ponovo.\n";
					row = col = -1;
				}
			} while (!Mineboard::index_in_range(row, col, board.get_width(), board.get_height()) || board.square_at(row, col).is_revealed());


			board.squaresLeft--;
			board.place_mines(row, col, numberOfMines); //popunjavanje minama u skladu sa dosadasnjim prikazanim stanjem
			board.draw_board(true);
			std::cout << "Ups! Stali ste na minu. Izgubili ste " << width * height - numberOfMines - 1 << " poena. Vise srece drugi put! \n";
			return points - pointsToLose;
		}
	}

}
