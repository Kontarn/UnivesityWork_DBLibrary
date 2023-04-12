#include "EditDBForm.h"

System::Void DBLibClient::EditDBForm::âûõîäÈçÏðîãðàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::EditDBForm::âûõîäÍàÍà÷àëüíûéÝêðàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::EditDBForm::BackToFindButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	FindForEditForm^ form = gcnew FindForEditForm();
	this->Hide();
	form->Show();
}
