#include"Game2.h"
#include<fstream>
#include<iostream>
#include<random>
#include <iomanip>

constexpr int num_of_Q = 5;
const int num_of_AQ = 5;
const int width = 45;
int Question::counter = 0;

Question::Question(difficulty MODE) :mode(MODE) {
	queNum = counter++;
	chooseQuestion();
}

Question::Question() : Question(difficulty::hard) {}

Question::~Question() {}

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

void color_Text(std::string text, int color) {
	std::cout << text;
}

void frame(std::string text, char mode = ' ') {
	char letter[3] = { mode,(mode == ' ') ? ' ' : 58 };
	std::string s(letter);
	if ((mode >= '0') && (mode <= '9'))std::cout << "      " << std::fixed << std::setw(2 * width - 1) << std::setfill('_') << "" << std::endl;
	if ((mode >= '0') && (mode <= '9'))std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	if ((mode >= '0') && (mode <= '9'))std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	std::cout << "     |" << std::fixed << std::setw(width + (text.length() / 2)) << std::setfill(' ');
	color_Text((s + text), ((mode >= '0') && (mode <= '9')) ? 15 : mode % 14); std::cout << std::setw(width - (text.length() / 2)) << "|" << std::endl;
	std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	if ((mode >= '0') && (mode <= '9'))std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	std::cout << "      " << std::fixed << std::setw(2 * width) << std::setfill('~') << " " << std::endl;
}

void Question::draw() {
	frame(text, (char)48 + queNum);
	frame(answer[0].text, 'A');
	frame(answer[1].text, 'B');
	frame(answer[2].text, 'C');
}


int Question::answerIt() {
	char ans; int index;
	std::cout << "The answer is: "; std::cin >> ans;
	index = (ans < 'Z') ? ans - 'A' : ans - 'a';
	if ((index > 2) || (index < 0)) { std::cout << "Try again buddy:" << std::endl; return answerIt(); }
	std::cout << "Are you sure "; color_Text(answer[index].text, index + 6); std::cout << "  is the right answser(y/n):";
	std::cin >> ans;
	if ((ans == 'y') || (ans == 'Y')) {
		std::cout << "You chose.... ";
		if (answer[index].is_Correct) {
			std::string tmp("wisely");
			color_Text(tmp, 2); return 20;
		}
		else {
			std::string tmp("poorly");
			color_Text(tmp, 7); return -30;
		}
	}
	else return answerIt();
	std::cout << std::endl;
	return 0;
}

int game2(int points, double percentage) {
	int offset = 0;
	std::cout << "Starting points:" << points << std::endl;
	Question q[num_of_Q];
	for (int i = 0; i < num_of_Q; ++i) {
		q[i].draw();
		offset += q[i].answerIt();
		std::cout << std::endl;
		std::cout << "Points:" << points + offset << std::endl;
	}
	if (offset == 100)offset += 50;
	return points + offset;
}
