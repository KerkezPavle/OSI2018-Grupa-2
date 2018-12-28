#include "HomeForm.h"
#include <Windows.h>

using namespace CLTTestApp;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew HomeForm());
	return 0;
}
