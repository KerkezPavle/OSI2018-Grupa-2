#include"Game2.h"
#include<fstream>
#include<iostream>
#include<random>

constexpr int num_of_Q = 5;
const int num_of_AQ = 5;
int Question::counter = 0;

Question::Question(difficulty MODE) :mode(MODE) {
	queNum = counter++;
	chooseQuestion();
}

Question::Question() : Question(difficulty::hard) {}

Question::~Question() {}

void game2(int points, double percentage) {
	Question q[num_of_Q];
}

int Question::chooseQuestion() {
	std::string tmp;
	static int used[num_of_Q] = { -1,-1,-1,-1,-1 };
	std::random_device rd;
	int num = rd() % (num_of_AQ);
	for (int i : used) {
		if (num == i) return chooseQuestion();
	}
	used[queNum] = num;
	std::string location = "assets//data//QandA.txt";
	std::ifstream file(location);
	if (file.is_open()) {
		for (int i = 0; i < num * 2; i++) {
			std::getline(file, tmp);
		}
		file >> text;
		for (auto& p : answer) {
			file >> p.text >> p.is_Correct;
		}
		file.close();
		return 1;
	}
	else std::cout << "File did not open!!!";
	return 0;
}