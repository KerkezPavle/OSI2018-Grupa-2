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
	const char *XMLFileName = "assets/config/ScoreBoard.xml";
	tinyxml2::XMLDocument xmlDoc;
	int counter;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement *parentGame;
	//First game
	myfile << "Prva igra:\n";
	myfile << ", Rang, Rezultat, Datum\n";
	parentGame = getParentGame(xmlDoc, 1);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Secod game
	myfile << "Druga igra:\n";
	myfile << ", Rang, Rezultat, Datum\n";
	parentGame = getParentGame(xmlDoc, 2);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Third game
	myfile << "Treca igra:\n";
	myfile << ", Rang, Rezultat, Datum\n";
	parentGame = getParentGame(xmlDoc, 3);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile << "\n\n";
	//Fourth game
	myfile << "Cetvrta igra:\n";
	myfile << ", Rang, Rezultat, Datum\n";
	parentGame = getParentGame(xmlDoc, 4);
	counter = 1;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		myfile << "," << counter++ << "," << child->FirstChildElement("value")->GetText() << "," << child->FirstChildElement("date")->GetText() << "\n";
	}
	myfile.close();
}