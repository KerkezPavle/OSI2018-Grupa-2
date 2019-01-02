#include"Game2.h"

Question::Question(int Qnum, difficulty MODE) :mode(MODE), queNum(Qnum) {}

Question::Question() : Question(0, difficulty::hard) {}

Question::~Question() {}

void game2(int points, double percentage) {
	Question q{};
}
