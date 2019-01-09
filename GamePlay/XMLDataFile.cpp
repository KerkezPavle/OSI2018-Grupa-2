#include "XMLDataFile.h"
#include "tinyxml2.h"
#include <Windows.h>
#include "Username.h"
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include "loto.h"
#include "Game4.h"
#include "Game1.h"
#include "Game2.h"
#include "PointsManipulation.h"
#include <functional>
using namespace tinyxml2;


/*HELPER FUNCTIONS - Only for interlan file use*/
/*----------------------------------------------*/


/*
	@desc: Helper function that gets XMLElement of parent
	@tested: working
*/
XMLElement* getParentGame(tinyxml2::XMLDocument& xmlDoc, int game) {
	switch (game)
	{
	case 1:
		return xmlDoc.FirstChildElement("Statistics")->FirstChildElement("FirstGame");
	case 2:
		return xmlDoc.FirstChildElement("Statistics")->FirstChildElement("SecondGame");
	case 3:
		return xmlDoc.FirstChildElement("Statistics")->FirstChildElement("ThirdGame");
	case 4:
		return xmlDoc.FirstChildElement("Statistics")->FirstChildElement("FourthGame");
	default:
		return 0;
	}
}

/*
	@desc: Helper: Sorts all scores in the file
	@tested: not working
*/
void sortGameResults(const char* XMLFileName) {
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement* parentGame = getParentGame(xmlDoc, 1);
	XMLElement* arr[10];
	int count = 0;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		arr[count++] = child;
	}

	XMLElement* temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			int a = std::stoi(arr[i]->FirstChildElement("value")->GetText());
			int b = std::stoi(arr[j]->FirstChildElement("value")->GetText());
			if (a > b) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (parentGame->FirstChild() == NULL)
			parentGame->InsertFirstChild(arr[i]);
		else
			parentGame->InsertEndChild(arr[i]);
	}

	xmlDoc.SaveFile(XMLFileName);

	xmlDoc.LoadFile(XMLFileName);
	parentGame = getParentGame(xmlDoc, 2);
	arr[10] = {NULL};
	count = 0;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		arr[count++] = child;
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			int a = std::stoi(arr[i]->FirstChildElement("value")->GetText());
			int b = std::stoi(arr[j]->FirstChildElement("value")->GetText());
			if (a > b) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (parentGame->FirstChild() == NULL)
			parentGame->InsertFirstChild(arr[i]);
		else
			parentGame->InsertEndChild(arr[i]);
	}

	xmlDoc.SaveFile(XMLFileName);

	xmlDoc.LoadFile(XMLFileName);
	parentGame = getParentGame(xmlDoc, 3);
	arr[10] = { NULL };
	count = 0;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		arr[count++] = child;
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			int a = std::stoi(arr[i]->FirstChildElement("value")->GetText());
			int b = std::stoi(arr[j]->FirstChildElement("value")->GetText());
			if (a > b) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (parentGame->FirstChild() == NULL)
			parentGame->InsertFirstChild(arr[i]);
		else
			parentGame->InsertEndChild(arr[i]);
	}

	xmlDoc.SaveFile(XMLFileName);

	xmlDoc.LoadFile(XMLFileName);
	parentGame = getParentGame(xmlDoc, 4);
	arr[10] = { NULL };
	count = 0;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		arr[count++] = child;
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			int a = std::stoi(arr[i]->FirstChildElement("value")->GetText());
			int b = std::stoi(arr[j]->FirstChildElement("value")->GetText());
			if (a > b) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (parentGame->FirstChild() == NULL)
			parentGame->InsertFirstChild(arr[i]);
		else
			parentGame->InsertEndChild(arr[i]);
	}

	xmlDoc.SaveFile(XMLFileName);
}

/*
	@desc: Helper: Gets the smalest score of the game
	@tested: working
*/
XMLElement* getSmallest(tinyxml2::XMLDocument& xmlDoc, int game) {
	XMLElement* minChild, *child;
	XMLElement* parentGame = getParentGame(xmlDoc, game);
	minChild = parentGame->FirstChildElement("Score");
	for (child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		if (std::stoi(child->FirstChildElement("value")->GetText()) < std::stoi(minChild->FirstChildElement("value")->GetText())) {
			minChild = child;
		}
	}
	return minChild;

}

/*
	@desc: Helper - Deletes smallest score of the game
*/
void deleteDataFromStats(const char* XMLFileName, int game) {
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement* child = getSmallest(xmlDoc, game);
	XMLElement* parentGame = getParentGame(xmlDoc, game);
	std::cout << std::stoi(child->FirstChildElement("value")->GetText());
	parentGame->DeleteChild(child);
	xmlDoc.SaveFile(XMLFileName);
}

/*----------------------------------------------*/
/* MAIN FUNCTIIONS */


/*
	@desc: Function deletes XML score file
	@tested: working
*/
void delXMLFile() {
	system("del ScoreBoard.xml");
}




/*
	@desc: Function for reading and displaying XML data
	@parm: tinyxml2::XMLDocument doc
	@tested: working
*/
void readXMLFile(const char* XMLFileName, int game) {
	tinyxml2::XMLDocument xmlDoc;
	int counter = 1;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement *parentGame = getParentGame(xmlDoc, game);
	std::cout << "===========================" << std::endl;
	std::cout << "---- STATISTIC GAME: " << game << " ----" << std::endl;
	std::cout << "===========================" << std::endl << std::endl;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		std::cout << counter++ << ". Place:" << std::endl << std::endl;
		std::cout << "Date:" << child->FirstChildElement("date")->GetText() << std::endl;
		std::cout << "Score:" << child->FirstChildElement("value")->GetText() << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
}

/*
	@decs: Function that checks does the file already exists and if not, creates a new one
	@parm: Name of the file
	@tested: works
*/
int makeXMLScoreFileSafe() {
	const char *XMLFileName = "assets/config/ScoreBoard.xml";
	tinyxml2::XMLDocument xmlDoc;
	if (xmlDoc.LoadFile(XMLFileName) == 3) {
		makeXMLSroreFile(XMLFileName);
		return 1;
	}
	return 0;
}

/*
	@desc: Function makes new XML score file
	@tested: works
*/
void makeXMLSroreFile(const char *XMLFileName) {
	tinyxml2::XMLDocument xmlDoc;
	XMLNode *pRoot = xmlDoc.NewElement("Statistics");
	xmlDoc.InsertFirstChild(pRoot);
	XMLElement *pFirstGame = xmlDoc.NewElement("FirstGame");
	XMLElement *pSecondGame = xmlDoc.NewElement("SecondGame");
	XMLElement *pThirdGame = xmlDoc.NewElement("ThirdGame");
	XMLElement *pFourthGame = xmlDoc.NewElement("FourthGame");
	pRoot->InsertFirstChild(pFirstGame);
	pRoot->InsertEndChild(pSecondGame);
	pRoot->InsertEndChild(pThirdGame);
	pRoot->InsertEndChild(pFourthGame);
	xmlDoc.SaveFile(XMLFileName);
}

int makeXMLSettingsFileSave() {
	const char* XMLFileName = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	if (xmlDoc.LoadFile(XMLFileName) == 3) {
		makeXMLSettingsFile();
		return 1;
	}
	return 0;
}


bool makeXMLSettingsFile() {
	const char* XMLFileName = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	XMLNode *pRoot = xmlDoc.NewElement("Settings");
	xmlDoc.InsertFirstChild(pRoot);
	XMLElement *username = xmlDoc.NewElement("Username");
	XMLElement *activeScore = xmlDoc.NewElement("ActiveScore");
	activeScore->SetText(10);
	pRoot->InsertFirstChild(username);
	pRoot->InsertEndChild(activeScore);
	xmlDoc.SaveFile(XMLFileName);
	return true;
}

/*
	@desc:Function that insets new score into file
	@parm: Filename, game number and score number
	@tested: working
*/
bool insertDataIntoStats(int game, int score) {
	const char* XMLFileName = "assets/config/ScoreBoard.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(XMLFileName);
	XMLElement* parentGame = getParentGame(xmlDoc, game);

	int count = 0;
	for (XMLElement *child = parentGame->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		count++;
	}



	xmlDoc.SaveFile(XMLFileName);
	xmlDoc.LoadFile(XMLFileName);
	parentGame = getParentGame(xmlDoc, game);

	if (count < 10 || score > std::stoi(getSmallest(xmlDoc, game)->FirstChildElement("value")->GetText())) {
		if (count >= 10) { std::cout << "Current: " << count << std::endl; deleteDataFromStats(XMLFileName, game); }
		xmlDoc.LoadFile(XMLFileName);
		parentGame = getParentGame(xmlDoc, game);
		time_t result = time(NULL);
		char time[26];
		ctime_s(time, sizeof time, &result);
		XMLElement *pScore = xmlDoc.NewElement("Score");
		XMLElement *pElementDate = xmlDoc.NewElement("date");
		XMLElement *pElementValue = xmlDoc.NewElement("value");
		time[strlen(time) - 1] = '\0';
		pElementDate->SetText(time);
		pElementValue->SetText(score);
		pScore->InsertFirstChild(pElementDate);
		time[std::strlen(time) - 1] = 0;
		pScore->InsertAfterChild(pElementDate, pElementValue);
		XMLElement *child = parentGame->FirstChildElement();
		if (child != NULL) {
			parentGame->InsertEndChild(pScore);
		}
		else {
			parentGame->InsertFirstChild(pScore);
		}
		xmlDoc.SaveFile(XMLFileName);
	}
	sortGameResults(XMLFileName);
	return true;
}


bool isUserNameSet() {
	const char* XMLFileName = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(XMLFileName);
	if (xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username")->GetText() == nullptr)
		return false;
	else
		return true;
	
}

bool setUserName(std::string username)
{
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	XMLElement *element = xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username");
	element->SetText(username.c_str());
	xmlDoc.SaveFile(SettingsXMLFile);
	return true;
}

const char* getCSVFileNameChar() {
	const char *c;
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	c = xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username")->GetText();
	char *a;
	strcpy(a, c);
	char*x = strcat(a, ".csv");
	xmlDoc.SaveFile(SettingsXMLFile);
	return x;
}



System::String^ getUsername() {
	const char *c;
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	c = xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username")->GetText();
	xmlDoc.SaveFile(SettingsXMLFile);
	System::String^ strNew = gcnew System::String(c);
	return strNew;
}

const char* getUsernameChars() {
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	return xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username")->GetText();
}

void clearUsername() {
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	xmlDoc.FirstChildElement("Settings")->FirstChildElement("Username")->SetText("");
	xmlDoc.SaveFile(SettingsXMLFile);
	GamePlay::Username frm;
	frm.ShowDialog();
}

int getActiveScore() {
	const char *c;
	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	c = xmlDoc.FirstChildElement("Settings")->FirstChildElement("ActiveScore")->GetText();
	xmlDoc.SaveFile(SettingsXMLFile);
	std::stringstream strValue;
	strValue << c;
	unsigned int intValue;
	strValue >> intValue;
	xmlDoc.SaveFile(SettingsXMLFile);
	return intValue;
}

void setActiveScore(int val) {

	const char* SettingsXMLFile = "assets/config/Settings.xml";
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(SettingsXMLFile);
	XMLElement *element = xmlDoc.FirstChildElement("Settings")->FirstChildElement("ActiveScore");
	element->SetText(val);
	xmlDoc.SaveFile(SettingsXMLFile);
}

/*
	@desc: This function overrides Close (X) button operation
*/

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal. 
	//case CTRL_C_EVENT:
	//	Beep(750, 300);
	//	return TRUE;

		// CTRL-CLOSE: confirm that the user wants to exit. 
	case CTRL_CLOSE_EVENT:
		Beep(600, 200);
		system("start ../x64/Debug/GamePlay.exe");
		return TRUE;

		// Pass other signals to the next handler. 
	case CTRL_BREAK_EVENT:
		Beep(900, 200);
		printf("Ctrl-Break event\n\n");
		return TRUE;

	case CTRL_LOGOFF_EVENT:
		Beep(1000, 200);
		printf("Ctrl-Logoff event\n\n");
		return FALSE;

	case CTRL_SHUTDOWN_EVENT:
		Beep(750, 500);
		printf("Ctrl-Shutdown event\n\n");
		return FALSE;

	default:
		return FALSE;
	}
}


void testFun(int n) {
	AllocConsole();
	SetConsoleCtrlHandler(CtrlHandler, TRUE);
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	int points = getActiveScore();
	if (n == 1) game_call(1, points);
	if (n == 2) game_call(2, points);
	if (n == 3) game_call(3, points);
	if (n == 4) game_call(4, points);
	system("pause");
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	FreeConsole();
}

void testTest() {
	int a;
	std::cin >> a;
	std::cout << a;
}