#include "HomeForm.h"
#include "Username.h"
#include "XMLDataFile.h"
#include <Windows.h>

using namespace GamePlay;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	makeXMLSettingsFileSave();
	makeXMLScoreFileSafe();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	if (isUserNameSet()) {
		Application::Run(gcnew HomeForm());
	}
	else {
		Username frm;
		frm.ShowDialog();
		Application::Run(gcnew HomeForm());
		
	}
	return 0;
}
