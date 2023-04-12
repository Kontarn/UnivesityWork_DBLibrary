#include "FindTechBookForm.h"

System::Void DBLibClient::FindTechBookForm::âûõîäÈçÏðîãðàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::FindTechBookForm::âûõîäÂÍà÷àëüíîåÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
