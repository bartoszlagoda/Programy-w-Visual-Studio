#include "Formatka.h"

using namespace System; // u�ycie systemowej przestrzeni nazw

// za pomoc� operatora zakresu odwo�ujemy si� do odpowiednich informacji
using namespace System::Windows::Forms;

[STAThread]

//ustalanie funkcji main nic nie zwracaj�cej
// jako argument ustawienie wska�nika na tablic� argument�w
void Main(array<String^>^ args)
{
	// w aplikacji uzywamy odpowiednich styl�w
	Application::EnableVisualStyles;
	//ustawienie domy�lnej aplikacji www
	Application::SetCompatibleTextRenderingDefault(false);
	//odwo�anie do odpowiedniej formy ju� w naszym programie
	WitajSwiecie_1::Formatka form;
	//uruchomienie aplikacji z podanym argumentem "form"
	Application::Run(%form);
}