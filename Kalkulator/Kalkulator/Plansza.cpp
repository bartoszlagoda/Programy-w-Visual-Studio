#include "Plansza.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kalkulator::Plansza formularz;
	Application::Run(%formularz);
	return 0;
}