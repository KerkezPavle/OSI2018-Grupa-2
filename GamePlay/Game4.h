#pragma once
#define DIMENSION 10
#define MINENUM 20

class Mineboard
{
public:
	Mineboard();
	~Mineboard();

	
	void uncover_square(int, int);// setting revealed status of said square and neighbour squares if needed
	int how_many_left() const { return squaresLeft; } // returns number of uncovered squares
	
	

private:

	class Square

	{
		friend class Mineboard;
	public:
		enum class State { Hidden, Revealed };
		void put_mine() { isMine = true; }
		bool has_mine() const { return isMine; }
		void set_revealed_state (int count) ;
		

	private:
		bool isMine = false;
		State state = State::Hidden; 
		char revealedState; //if mine is uncovered constains number of neighbour mines  or blank if it doesen't hold information

	};


	static constexpr int width = DIMENSION;
	static constexpr int height = DIMENSION;
	unsigned squaresLeft = width * height; //initial value, will be decremented
	Square board[width*height];


	
public:
	Square& square_at(int, int); //used for accessing the square at given coordinates
	static bool index_in_range(int, int);

};

