#include "StartMenuForm.h"

#include <Windows.h>	
using namespace DBLibClient;

[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew StartMenuForm);
	return 0;
}



System::Void DBLibClient::StartMenuForm::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}


System::Void DBLibClient::StartMenuForm::DataBaseSearch_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	LibrarySearchForm^ form = gcnew LibrarySearchForm();
	this->Hide();
	form->Show();
}


System::Void DBLibClient::StartMenuForm::AdminButt_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}


