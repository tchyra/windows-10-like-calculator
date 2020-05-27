#include "FrmCalculator.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	win10calccpp::FrmCalculator form;
	Application::Run(% form);
}
