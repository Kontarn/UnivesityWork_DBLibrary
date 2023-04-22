#include "SearchBookForm.h"

System::Void DBLibClient::SearchBookForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::SearchBookForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
    StartMenuForm^ form = gcnew StartMenuForm();
    this->Hide();
    form->Show();
}

System::Void DBLibClient::SearchBookForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
