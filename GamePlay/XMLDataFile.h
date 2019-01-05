#pragma once
#include "tinyxml2.h"
#include <string>

/*
@desc: Function deletes XML score file
@tested: works
*/
void delXMLFile();

/*
@desc: Function for reading and displaying XML data
@parm: XMLDocument doc
@tested: working
*/
void readXMLFile(const char* XMLFileName, int game);

tinyxml2::XMLElement* getParentGame(tinyxml2::XMLDocument& xmlDoc, int game);
int makeXMLScoreFileSafe();
void makeXMLSroreFile(const char *XMLFileName);
bool insertDataIntoStats(int game, int score);
void deleteDataFromStats(const char* XMLFileName, int game);
void sortGameResults(const char* XMLFileName);
// Settings
bool makeXMLSettingsFile();
int makeXMLSettingsFileSave();
bool isUserNameSet();
bool setUserName(std::string);
System::String^ getUsername();
void clearUsername();
int getActiveScore();
void setActiveScore(int);
const char* getCSVFileNameChar();
void testFun();
void testTest(); 
