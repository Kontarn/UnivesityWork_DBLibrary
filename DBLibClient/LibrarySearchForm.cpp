#include "LibrarySearchForm.h"



System::Void DBLibClient::LibrarySearchForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::LibrarySearchForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
    StartMenuForm^ form = gcnew StartMenuForm;
    this->Hide();
    form->Show();
}

System::Void DBLibClient::LibrarySearchForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("��� ������ �� ����� ��� ������ ��������� ��������� ��������������� ���������� �������,	\
���� ������������ ��� ������ (�������� �����, ��� ������, ��� ������� �����)									\
\n������: ����� � ���, �.�. ������� ��� ����� � ���, �.�. �������, 1865", "��������");
}

System::Void DBLibClient::LibrarySearchForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	System::String^ request = nameBookTextBox->Text; // �������� ������ ��� ������ �����
	System::String^ typeOfLit = choiceOfTypeBook->Text; // ��� ��������� ����������
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer(); 
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sRequest(cRequest);
	std::string sTypeOfLit(cTypeOfLit);
	std::vector <std::string> littleDB;
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease;
	std::string availability; // ������� ����� � ����������
	size_t i = 0;
	User user;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("����������, ��������� ��� ����", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {
		// ���� ���������� � ��������
		user.searchByRequest(&littleDB, sRequest, sTypeOfLit);
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		if (littleDB.size() != 0) {
			do
			{
				// ��������� ������ �� ������� �� ���������, ��� ������ � �������
				user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
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

		user.searchByRequest(&littleDB, sRequest, sTypeOfLit);
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		if (littleDB.size() != 0) {
			do
			{
				user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
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

System::Void DBLibClient::LibrarySearchForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	setlocale(LC_ALL, "ru");
	User user;
	std::vector <std::string> littleDB;
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease; // ��� ������� �����
	std::string availability; // ���������� ����������� �����, � ����������
	bool flag = 0; // ������ �������� checkBox1, ������� ��������� ���������� �� ������ ����� � �������
	System::String^ typeOfLit = choiceOfTypeBook->Text; // ��� ��������� ����������
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sTypeOfLit(cTypeOfLit);
	size_t i = 0;
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	if (checkBox1->Checked == false)
		flag = 0;
	else if (checkBox1->Checked == true)
		flag = 1;

	if (choiceOfTypeBook->Text == "") MessageBox::Show("�������� ��� ���������� ��� ������", "��������");
	else if (choiceOfTypeBook->Text == "�����������") {
		user.showAllLines(littleDB, sTypeOfLit, flag); // ��������� � ������ littleDb, ��� �� ������� � �������
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		user.showAllLines(littleDB, sTypeOfLit, flag);
	}
	else if (choiceOfTypeBook->Text == "��� ����") {
		user.showAllLines(littleDB, sTypeOfLit, flag); // ��������� � ������ littleDb, ��� �� ������� � �������
	}
	// ������� ������ �� ������� � datagridview
	if (littleDB.size() != 0) {
		do
		{
			// ��������� ������ �� ��������� ��� ������ � �������
			user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
			System::String^ SnameBook = gcnew String(nameBook.c_str());
			System::String^ SnameAutor = gcnew String(nameAutor.c_str());
			System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
			System::String^ Savailability = gcnew String(availability.c_str());
			dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
			i++;
		} while (i < littleDB.size());
	}
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}
