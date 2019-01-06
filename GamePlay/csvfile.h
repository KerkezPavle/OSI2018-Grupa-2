#pragma once
#include <iostream>
#include <fstream>
#include "tinyxml2.h"
#include "XMLDataFile.h"
#include <cstring>
#include <vcclr.h>
using namespace tinyxml2;
void MakeCSV(const char * filename)
{
	std::ofstream myfile;
	myfile.open(filename);
	myfile << "Username: " << PtrToStringChars(getUsername()) <<  "\n";
	const char *XMLFileName = "ScoreBoard.xml";
	tinyxml2::XMLDocument xmlDoc;
	int counter;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement *parentGame;
	//First game
	myfile << "First game:\n";
	myfile << ", Place, Score, Date\n";
	parentGame = getParentGame(xmlDoc, 1);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Secod game
	myfile << "Second game:\n";
	myfile << ", Place, Score, Date\n";
	parentGame = getParentGame(xmlDoc, 2);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Third game
	myfile << "Third game:\n";
	myfile << ", Place, Score, Date\n";
	parentGame = getParentGame(xmlDoc, 3);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Fourth game
	myfile << "Rourth game:\n";
	myfile << ", Place, Score, Date\n";
	parentGame = getParentGame(xmlDoc, 4);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile.close();
}