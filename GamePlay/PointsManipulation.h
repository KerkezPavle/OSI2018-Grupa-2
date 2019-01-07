#pragma once
#include "XMLDataFile.h"
#include "Game1.h"
#include "Game2.h"
#include "loto.h"
#include "Game4.h"
#define CRITICAL 100
void game_call(int gameNum, int currentPoints)
{
	int newPoints;
	if (gameNum == 1)
	{
		int numPlayed;
		newPoints = game1(currentPoints, 0);
		numPlayed = ucitajBrojIgranja() - 1;
		if (numPlayed >= 3)
		{
			if (newPoints > currentPoints)
				newPoints *= 0.95;

		}
		insertDataIntoStats(1, newPoints - currentPoints);
		setActiveScore(newPoints);
	}
	else if (gameNum == 2)
	{
		newPoints = game2(currentPoints, 0.0);
		insertDataIntoStats(2, newPoints - currentPoints);
		setActiveScore(newPoints);
	}
	else if (gameNum == 3)
	{
		newPoints = lotoGame(currentPoints, 0.0);
		insertDataIntoStats(3, newPoints - currentPoints + CRITICAL);
		setActiveScore(newPoints);
	}
	else if (gameNum == 4)
	{
		int percentage;
		if (currentPoints > 250)percentage = 45;
		else if (currentPoints > 200 && currentPoints <= 250) percentage = 40;
		else if (currentPoints > 150 && currentPoints <= 200) percentage = 35;
		else if (currentPoints > 100 && currentPoints <= 150) percentage = 30;
		else if (currentPoints > 50 && currentPoints <= 100) percentage = 25;
		else if (currentPoints <= 50 && currentPoints > 20) percentage = 10;
		else percentage = 0;
		newPoints = Game4(currentPoints, percentage);
		insertDataIntoStats(4, newPoints - currentPoints + 100);
		setActiveScore(newPoints);
	}
	return;
}