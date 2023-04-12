#include "FindForEditForm.h"


System::Void DBLibClient::FindForEditForm::����������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::FindForEditForm::������������������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}



System::Void DBLibClient::FindForEditForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ nameBook = nameBookTextBox->Text;
	System::String^ typeOfLit = choiceOfTypeBook->Text;
	//System::String^ AutorName = nameAutorTextBox->Text;
	//System::String^ yearsOfRelease = yearsOfReleaseTextBox->Text;
	//System::String^ Availability = AvailabilityTextBox->Text;
	char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	//char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(AutorName).ToPointer();
	//char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearsOfRelease).ToPointer();
	//char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(Availability).ToPointer();
	std::string sNameBook(cNameBook);
	std::string sTypeOfLit(cTypeOfLit);
	//std::string sAutorName(cAutorName);
	//std::string sYearsOfRelease(cYearsOfRelease);
	//std::string sAvailability(cAvailability);
	if (choiceOfTypeBook->Text == "") MessageBox::Show("�������� ��� ���������� ��� ������", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {
		
		if (recordExistenceCheck(sNameBook, sTypeOfLit) == true) {
			EditDBForm^ form = gcnew EditDBForm();
			this->Hide();
			form->Show();
		}
		else {
			MessageBox::Show("������ ����������� � ���� ������ ����������� ���������� \
���� �������� ������ ���� ������, ���� �������� ������", "������");
		}
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		if (recordExistenceCheck(sNameBook, sTypeOfLit) == true) {
			EditDBForm^ form = gcnew EditDBForm();
			this->Hide();
			form->Show();
		}
		else {
			MessageBox::Show("������ ����������� � ���� ������ �������������� ���������� \
���� �������� ������ ���� ������, ���� �������� ������", "������");
		}
	}
	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);

	//Marshal::FreeHGlobal((IntPtr)cAutorName);
	//Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	//Marshal::FreeHGlobal((IntPtr)cAvailability);
}

System::Void DBLibClient::FindForEditForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ������ �� ����� ��� ������ ��������� ��������� ��������������� ���������� �������		\
		���� ������������ ��� ������(�������� �����, ��� ������, ��� ������� �����; ������� � ����������)		\
		\n������: ����� � ���, �.�. ������� ��� ����� � ���, �.�. �������, 1865", "��������");
}
