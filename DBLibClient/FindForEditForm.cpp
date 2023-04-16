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

	System::String^ request = nameBookTextBox->Text; // �������� ������
	System::String^ typeOfLit = choiceOfTypeBook->Text;
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer();
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sRequest(cRequest);
	std::string sTypeOfLit(cTypeOfLit);
	std::vector <std::string> littleDB;
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease;
	std::string availability;
	size_t i = 0;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("����������, ��������� ��� ����", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {
		TechLit tLit;
		tLit.searchByRequest(&littleDB, sRequest);
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		if (littleDB.size() != 0) {
			do
			{
				splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
				System::String^ SnameBook = gcnew String(nameBook.c_str());
				System::String^ SnameAutor = gcnew String(nameAutor.c_str());
				System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
				System::String^ Savailability = gcnew String(availability.c_str());
				dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
				i++;
			} while (i < littleDB.size());
		}
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		ArtLit ALit;
		ALit.searchByRequest(&littleDB, sRequest);
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		if (littleDB.size() != 0) {
			do
			{
				splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
				System::String^ SnameBook = gcnew String(nameBook.c_str());
				System::String^ SnameAutor = gcnew String(nameAutor.c_str());
				System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
				System::String^ Savailability = gcnew String(availability.c_str());
				dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
				i++;
			} while (i < littleDB.size());
		}
	}
	Marshal::FreeHGlobal((IntPtr)cRequest);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}

System::Void DBLibClient::FindForEditForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ������ �� ����� ��� ������ ��������� ��������� ��������������� ���������� �������		\
		���� ������������ ��� ������(�������� �����, ��� ������, ��� ������� �����; ������� � ����������)		\
		\n������: ����� � ���, �.�. ������� ��� ����� � ���, �.�. �������, 1865", "��������");
}

System::Void DBLibClient::FindForEditForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	TechLit Tlit;
	ArtLit Alit;
	std::vector <std::string> littleDB; 
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease; // ��� ������� �����
	std::string availability; // ���������� ����������� �����, � ����������
	size_t i = 0;
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	if (choiceOfTypeBook->Text == "") MessageBox::Show("�������� ��� ���������� ��� ������", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {
		Tlit.showAllLines(&littleDB); // ��������� � ������ littleDb, ��� �� ������� � �������
		if (littleDB.size() != 0) {
			do
			{
				splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
				System::String^ SnameBook = gcnew String(nameBook.c_str());
				System::String^ SnameAutor = gcnew String(nameAutor.c_str());
				System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
				System::String^ Savailability = gcnew String(availability.c_str());
				dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
				i++;
			} while (i < littleDB.size());
		}
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		Alit.showAllLines(&littleDB);
		if (littleDB.size() != 0) {
			do
			{
				splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
				System::String^ SnameBook = gcnew String(nameBook.c_str());
				System::String^ SnameAutor = gcnew String(nameAutor.c_str());
				System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
				System::String^ Savailability = gcnew String(availability.c_str());
				dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
				i++;
			} while (i < littleDB.size());
		}
	}
}

System::Void DBLibClient::FindForEditForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
