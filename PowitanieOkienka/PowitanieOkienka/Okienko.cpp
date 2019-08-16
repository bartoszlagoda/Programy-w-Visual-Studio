#include "Okienko.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowitanieOkienka::Okienko forma;
	Application::Run(%forma);
	return 0;
}

