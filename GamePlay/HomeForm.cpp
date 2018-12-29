#include "HomeForm.h"
#include "Username.h"
#include <Windows.h>

using namespace GamePlay;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	if (1) {
		Username frm;
		frm.ShowDialog();
		Application::Run(gcnew HomeForm());
	}
	else {
		Application::Run(gcnew HomeForm());
	}
	//Username frm;
	//frm.ShowDialog();
	return 0;
}
