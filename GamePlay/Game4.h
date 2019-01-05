#pragma once
#pragma once
#define STANDARDSIZE 8
#include <Windows.h>


class Mineboard
{
public:
	Mineboard(int, int);
	Mineboard(int, int, bool);
	~Mineboard();

	void draw_board(bool);// bool u slucaju da je igrac izgubio funkciji govori da otkrije sva polja
	void uncover_square(int, int);// otkriva dato polje i susjedna polja ako je potrebno
	int how_many_left() const { return squaresLeft; } // daje podatak koliko je polja ostalo neotkriveno
	static bool index_in_range(int, int, int, int); //provjera korisnickog unosa
	int count_close_mines(int, int);
	int count_hidden(int row, int col);
	bool surrounded_by_hidden(int, int);// provjerava da li je polje okruzeno skrivenim poljima
	int get_width() { return width; }
	int get_height() { return height; }
	void place_mines(int, int, int);
	bool are_neighbours(int, int, int, int);// provjerava da li su unesena mjesta za jedinice

	//susjedna i ako jesu stavlja minu na potrebno mjesto da bi se odrzao logicki poredak na tabeli



private:

	class Square

	{
		friend class Mineboard;
	public:
		enum class State { Hidden, Revealed };
		void put_mine() { isMine = true; }
		bool has_mine() const { return isMine; }
		bool is_revealed() { return state == State::Revealed ? true : false; }

		void draw_square(bool) const;
		void set_close_mines(int);
		void make_revealed() { state = State::Revealed; }




	private:
		bool isMine = false;
		State state = State::Hidden;
		int closeMines = '/'; //ako je polje otkriveno sadrzi broj susjednih mina

	};


	const int width;
	const int height;

	Square** board;

public:
	unsigned squaresLeft = width * height; //inicijalna vrijednost
	Square& square_at(int, int); //koristi se za pristup polju na datim koordinatama
private:
	static Square** allocate(int, int); // pomocna funkcija za alokaciju prostora za matricu







};

void calculate_dimension(int, int&, int&, int&); //funkcija za izracunavanje optimalne dimenzije tabele i broja mina za zadani broj bodova
void Game4(int, int);
void ClearScreen(); // funkcije koje se koriste za bojenje teksta i ciscenja ekrana
void setcolor(int);

#pragma once
