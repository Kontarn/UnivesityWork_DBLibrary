#include "FindArtBookForm.h"

System::Void DBLibClient::FindArtBookForm::âûõîäÈçÏðîãðàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::FindArtBookForm::âûõîäÂÍà÷àëüíîåÎêíîToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
