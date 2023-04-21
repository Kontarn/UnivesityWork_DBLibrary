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

System::Void DBLibClient::StartMenuForm::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::StartMenuForm::îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Ïðîãðàììà äëÿ ïîèñêà êíèã", "Î ïðîãðàììå");
}

System::Void DBLibClient::StartMenuForm::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}


System::Void DBLibClient::StartMenuForm::DataBaseSearch_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Ê ñîæàëåíèþ ïîèñê ïîêà íå ðàáîòàåò", "Ïðåäóïðåæäåíèå");
}

System::Void DBLibClient::StartMenuForm::AdminButt_Click(System::Object^ sender, System::EventArgs^ e)
{
	AutorizationForm^ form = gcnew AutorizationForm();
	this->Hide();
	form->Show();
}


