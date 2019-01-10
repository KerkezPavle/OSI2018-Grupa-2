#pragma once
#include<string>

struct Answer {
	std::string text;
	bool is_Correct = 0;
};

class Question {
	std::string text;
	Answer answer[4];
	int chooseQuestion();
	int queNum;
public:
	static int counter;
	void draw(int);
	int answerIt();
	Question();
	~Question();
};

int game2(int, double);
