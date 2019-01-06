#include"Game2.h"
#include<fstream>
#include<iostream>
#include<random>
#include <iomanip>
#include<windows.h>
#include"Game4.h"

constexpr int num_of_Q = 5;
const int num_of_AQ = 13;
const int width = 45;
int Question::counter = 0;

Question::Question(difficulty MODE) :mode(MODE) {
	queNum = counter++;
	chooseQuestion();
}

Question::Question() : Question(difficulty::hard) {}

Question::~Question() {}

int Question::chooseQuestion() {
	std::string tmp; int num;
	static int used[num_of_Q] = { -1,-1,-1,-1,-1 };
	std::random_device rd;
	if (queNum)num = rd() % (num_of_AQ)+1; else num = 0;
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
		std::replace(text.begin(), text.end(), '_', ' ');
		for (auto& p : answer) {
			file >> p.text >> p.is_Correct;
			std::replace(p.text.begin(), p.text.end(), '_', ' ');
		}
		file.close();
		return 1;
	}
	else std::cout << "File did not open!!!";
	return 0;
}

void color_Text(std::string text, int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void frame(std::string text, char mode = ' ') {
	char letter[3] = { mode,(mode == ' ') ? ' ' : 58 };
	std::string s(letter);
	if ((mode >= '0') && (mode <= '9')) {
		std::cout << "      " << std::fixed << std::setw(2 * width - 1) << std::setfill('_') << "" << std::endl;
		std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	}
	std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	if ((mode >= '0') && (mode <= '9'))std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	if (text.length() < 2 * width) {
		std::cout << "     |" << std::fixed << std::setw(width + (text.length() / 2)) << std::setfill(' ');
		color_Text(s + text, ((mode >= '0') && (mode <= '9')) ? 15 : (mode + 6) % 15 + 1); std::cout << std::setw(width - (text.length() / 2)) << "|" << std::endl;
	}
	else {
		std::cout << "     |" << std::fixed << std::setw(width + (text.length() / 4)) << std::setfill(' ');
		color_Text((s + " " + text.substr(0, (double)text.length() / 2)), ((mode >= '0') && (mode <= '9')) ? 15 : mode % 14); std::cout << std::setw(width - (text.length() / 4)) << "|" << std::endl;
		std::cout << "     |" << std::fixed << std::setw(width + (text.length() / 4)) << std::setfill(' ');
		color_Text((text.substr((double)(text.length() / 2), text.length())), ((mode >= '0') && (mode <= '9')) ? 15 : mode % 14); std::cout << std::setw(width - (text.length() / 4)) << "|" << std::endl;
	}
	std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	if ((mode >= '0') && (mode <= '9'))std::cout << "     |" << std::fixed << std::setw(2 * width) << std::setfill(' ') << "|" << std::endl;
	std::cout << "      " << std::fixed << std::setw(2 * width) << std::setfill('~') << " " << std::endl;
}

void Question::draw(int p = 0) {
	frame(text, (char)48 + queNum);
	frame(answer[0].text, 'A');
	if (queNum)frame(answer[1].text, 'B'); else frame(answer[1].text + ": " + std::to_string(p), ' ');
	frame(answer[2].text, 'C');
}


int Question::answerIt() {
	char ans; int index;
	std::cout << "The answer is: "; std::cin >> ans;
	index = (ans < 'Z') ? ans - 'A' : ans - 'a';
	if ((index > 2) || (index < 0)) { std::cout << "Try again buddy:" << std::endl; return answerIt(); }
	if (queNum == 0)return index;
	std::cout << "Are you sure "; color_Text(answer[index].text, index + 4); std::cout << "  is the right answer(y/n):";
	std::cin >> ans;
	if ((ans == 'y') || (ans == 'Y')) {
		std::cout << "You choose.... ";
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
	int offset = 0; int sch;
	Question start{};
	start.draw(points); sch = start.answerIt();
	if (sch == 2)return 0;
	ClearScreen();
	Question q[num_of_Q];
	for (int i = 0; i < num_of_Q; ++i) {
		q[i].draw();
		offset += q[i].answerIt();
		std::cout << std::endl;
		std::cout << "Points:" << points + offset << std::endl;
		std::cin.ignore(-1, '\n');
		std::cin.get();
		std::cin.get();
		ClearScreen();
	}
	if (offset == 100)offset += 50;
	return points + offset;
}
