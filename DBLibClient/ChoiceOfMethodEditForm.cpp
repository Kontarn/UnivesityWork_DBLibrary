#include "ChoiceOfMethodEditForm.h"

System::Void DBLibClient::ChoiceOfMethodEditForm::toStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::ChoiceOfMethodEditForm::âûõîäÍàÍà÷àëüíûéÝêðàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::ChoiceOfMethodEditForm::âûõîäÈçÏðîãðàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::ChoiceOfMethodEditForm::EditElementsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	FindForEditForm^ form = gcnew FindForEditForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::ChoiceOfMethodEditForm::AddElementsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddElementsToDBForm^ form = gcnew AddElementsToDBForm();
	this->Hide();
	form->Show();
}
