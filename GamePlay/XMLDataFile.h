#pragma once
#include "tinyxml2.h"
#include <string>


/*
	@desc: For testing purpose Function that reads XML file.
	@parms: const char* XMLFileName, int game
	@return: void
*/
void readXMLFile(const char* XMLFileName, int game);

/*
	@desc: Gets game tag in XML file
	@parms: XMLDocument document, int game
	@return: XMLElemetn*
*/
tinyxml2::XMLElement* getParentGame(tinyxml2::XMLDocument& xmlDoc, int game);

/*
	@desc: Checks if file exist, and if not calls makeXMLScoreFile()
	@parms: none
	@return: int (success or failure)
*/
int makeXMLScoreFileSafe();

/*
	@desc: Creates XML file for scoring system
	@parms: const char* FileName
	@return: void
*/
void makeXMLSroreFile(const char *XMLFileName);

/*
	@desc: Inserts data into stats, if score is good enought to be recored
	@parms: int game, int score
	@return: true or false
*/
bool insertDataIntoStats(int game, int score);

/*
	@desc: Deletes lowest score data entry from game stats
	@parms: const char* FileName, int game)
	@return: void
*/
void deleteDataFromStats(const char* XMLFileName, int game);

/*
	@desc: Sorts scores in data file
	@parms: const char* FileName
	@return: void
*/
void sortGameResults(const char* XMLFileName);

/*
	@desc: Checks if file exist, and if not calls makeXMLSettingsFile()
	@parms: none
	@return: int (success or failure)
*/
int makeXMLSettingsFileSave();
/*
	@desc: Creates XML settings file
	@parms: const char* FileName
	@return: true or false
*/
bool makeXMLSettingsFile();

/*
	@desc: Checks if Username is set
	@parms: none
	@returns: true or false
*/
bool isUserNameSet();

/*
	@desc: Sets new Username
	@parms: String username
	@return: true or false
*/
bool setUserName(std::string);

/*
	@desc: Gets currrent active username
	@parms: none
	@return: System::String^ username
*/
System::String^ getUsername();

/*
	@desc: Clears active username
	@parms: none
	@return: void
*/
void clearUsername();

/*
	@desc: Returns active score
	@parms: none
	@return: int
*/
int getActiveScore();

/*
	@desc: Sets new active score
	@parms: int newScore
	@return: void
*/
void setActiveScore(int);

/*
	@desc: Returns CSV Filename: Username + csv extention
	@parms: none
	@return: const char*
*/
const char* getCSVFileNameChar();

/*
	@desc: Makes calls to scoring system function that opens each game
	@parms: int game
	@return: void
*/
void runGames(int);

/*
	@desc: Returns active username as char
	@parms: none
	@return: const char*
*/
const char* getUsernameChars();
