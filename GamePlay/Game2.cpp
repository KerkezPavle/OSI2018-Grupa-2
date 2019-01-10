#include"Game2.h"
#include<fstream>
#include<iostream>
#include<random>
#include <iomanip>
#include<windows.h>
#include"Game4.h"

constexpr int NUM_OF_Q = 5;
const int NUM_OF_AQ = 15;
const int WIDTH = 45;
int Question::counter = 0;

Question::Question() :queNum(counter++) {
	chooseQuestion();
}

int Question::chooseQuestion() {  //odabir i ucitavanje pitanja iz .txt fajla
	std::string tmp;
	std::random_device rd;
	int Qnum; static int used[NUM_OF_Q] = { -1,-1,-1,-1,-1 };
	if (queNum == 0) {
		for (int& i : used)
			i = -1;
	}
	Qnum = (queNum) ? rd() % (NUM_OF_AQ)+1 : 0;
	for (int i : used) {
		if (Qnum == i) return chooseQuestion();
	}
	if (queNum != 0)used[queNum - 1] = Qnum;
	std::string location = "assets//data//QandA.txt";
	std::ifstream file(location);
	if (file.is_open()) {
		for (int i = 0; i < Qnum * 2; i++) {
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
	else {
		std::cout << "File did not open!!!";
	}
	return 0;
}

void color_Text(std::string text, int color) {	//oboji string na std::out
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void recuringLine() { //cesto se ponavlja kod
	std::cout << "     |" << std::fixed << std::setw(2 * WIDTH) << std::setfill(' ') << "|" << std::endl;
}

void frame(std::string text, char mode = ' ') {		//tipovi okvira
	char letter[3] = { mode,(mode == ' ') ? ' ' : 58 };
	bool isQuestion = (mode >= '0') && (mode <= '9');
	std::string s(letter);
	if (isQuestion) {
		std::cout << "      " << std::fixed << std::setw(2 * WIDTH - 1) << std::setfill('_') << "" << std::endl;
		recuringLine();
	}
	recuringLine();
	if (isQuestion)	recuringLine();
	if (text.length() < 2 * WIDTH) {
		std::cout << "     |" << std::fixed << std::setw(WIDTH + (text.length() / 2)) << std::setfill(' ');
		color_Text(s + text, (isQuestion) ? 15 : (mode + 6) % 15 + 1); std::cout << std::setw(WIDTH - (text.length() / 2)) << "|" << std::endl;
	}
	else {
		std::cout << "     |" << std::fixed << std::setw(WIDTH + (text.length() / 4)) << std::setfill(' ');
		color_Text((s + " " + text.substr(0, (double)text.length() / 2)), (isQuestion) ? 15 : mode % 14);
		std::cout << std::setw(WIDTH - (text.length() / 4)) << "|" << std::endl;
		std::cout << "     |" << std::fixed << std::setw(WIDTH + (text.length() / 4)) << std::setfill(' ');
		color_Text((text.substr((double)(text.length() / 2), text.length())), (isQuestion) ? 15 : mode % 14);
		std::cout << std::setw(WIDTH - (text.length() / 4)) << "|" << std::endl;
	}
	recuringLine();
	if (isQuestion)	recuringLine();
	std::cout << "      " << std::fixed << std::setw(2 * WIDTH) << std::setfill('~') << " " << std::endl;
}

void Question::draw(int p = 0) {		//ispis pitanja i odgovora
	frame(text, (char)48 + queNum);
	frame(answer[0].text, 'A');
	if (queNum)frame(answer[1].text, 'B'); else frame(answer[1].text + ": " + std::to_string(p), ' ');
	frame(answer[2].text, 'C');
}


int Question::answerIt() {	// odgovor na pitanje
	std::string ans; int index;
	std::cout << "Odgovor je pod: ";
	std::cin >> ans;
	if ((ans == "A") || (ans == "a"))index = 0;
	else if ((ans == "B") || (ans == "b"))index = 1;
	else if ((ans == "C") || (ans == "c"))index = 2;
	else return answerIt();
	if (queNum == 0) return index;
	std::cout << "Jeste li sigurni \""; color_Text(answer[index].text, index + 4); std::cout << "\" je ispravan odgovor?(y/n):";
	std::cin >> ans;
	if ((ans == "y") || (ans == "Y")) {
		std::cout << "Odgovor je.... ";
		if (answer[index].is_Correct) {
			ans = "tacan.";
			color_Text(ans, 2); return 20;
		}
		else {
			ans = "netacan.";
			color_Text(ans, 7); return -30;
		}
	}
	else return answerIt();
	std::cout << std::endl;
	return 0;
}

int game2(int points, double percentage) { //glavna funkcija
	int offset = 0;
	Question::counter = 0;
	Question start{};
	start.draw(points);
	if (start.answerIt() == 2) {
		return points;
	}
	ClearScreen();
	Question q[NUM_OF_Q];
	for (int i = 0; i < NUM_OF_Q; ++i) { //osnovni game loop
		q[i].draw();
		offset += q[i].answerIt();
		std::cout << std::endl;
		std::cout << "Poeni:" << points + offset << std::endl;
		std::cin.ignore(-1, '\n');
		std::cin.get();
		std::cin.get();
		ClearScreen();
	}
	if (offset == 100)offset += 50;
	return points + offset;
}