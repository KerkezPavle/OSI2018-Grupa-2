#pragma once
#define DIMENSION 10
#define MINENUM 20

// used for output manipulation, used for colouring text and background
static constexpr auto RED = "\x1b[31;1m";
static constexpr auto GREEN = "\x1b[32;1m";
static constexpr auto BLUE = "\x1b[34;1m";
static constexpr auto TILE = "\x1b[30;47m";
static constexpr auto RESET = "\x1b[0m";
static constexpr auto CLEAR = "\x1b[2J";

class Mineboard
{
public:
	Mineboard();
	~Mineboard();

	void draw_board(bool);// bool shows if you should reveal every square on the board (in case someone loses)
	void uncover_square(int, int);// setting revealed status of said square and neighbour squares if needed
	int how_many_left() const { return squaresLeft; } // returns number of uncovered squares
	static bool index_in_range(int, int); //static function to check and control user input
	
	
	

private:

	class Square

	{
		friend class Mineboard;
	public:
		enum class State { Hidden, Revealed };
		void put_mine() { isMine = true; }
		bool has_mine() const { return isMine; }
		void set_close_mines (int count) ;
		void draw_square(bool) const; // bool data shows if the square should be revealed no matter what (in case of losing)
		void set_close_mines(int);
		void make_revealed() { state = State::Revealed; }
		

	private:
		bool isMine = false;
		State state = State::Hidden; 
		int closeMines; //if mine is uncovered constains number of neighbour mines  or blank if it doesen't hold information

	};


	static constexpr int width = DIMENSION;
	static constexpr int height = DIMENSION;
	unsigned squaresLeft = width * height; //initial value, will be decremented
	Square board[width][height];

public:
	Square& square_at(int, int); //used for accessing the square at given coordinates

	

	

};

