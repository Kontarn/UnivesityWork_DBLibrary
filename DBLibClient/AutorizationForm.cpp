#include "AutorizationForm.h"

System::Void DBLibClient::AutorizationForm::выходЌаЌачальныйЁкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::AutorizationForm::выход»зѕрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::AutorizationForm::BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::AutorizationForm::Autorization_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (textBox1->Text == "Admin") {
		ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
		this->Hide();
		form->Show();
	} 
	else {
		MessageBox::Show("Ќеверный код доступа, повторите попытку", "ќшибка");
	}
}
