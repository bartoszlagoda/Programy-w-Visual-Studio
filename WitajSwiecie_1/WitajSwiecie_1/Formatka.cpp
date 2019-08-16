#include "Formatka.h"

using namespace System; // u¿ycie systemowej przestrzeni nazw

// za pomoc¹ operatora zakresu odwo³ujemy siê do odpowiednich informacji
using namespace System::Windows::Forms;

[STAThread]

//ustalanie funkcji main nic nie zwracaj¹cej
// jako argument ustawienie wskaŸnika na tablicê argumentów
void Main(array<String^>^ args)
{
	// w aplikacji uzywamy odpowiednich stylów
	Application::EnableVisualStyles;
	//ustawienie domyœlnej aplikacji www
	Application::SetCompatibleTextRenderingDefault(false);
	//odwo³anie do odpowiedniej formy ju¿ w naszym programie
	WitajSwiecie_1::Formatka form;
	//uruchomienie aplikacji z podanym argumentem "form"
	Application::Run(%form);
}