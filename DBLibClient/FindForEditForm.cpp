#include "FindForEditForm.h"

// ������ ����� �� ���������
System::Void DBLibClient::FindForEditForm::����������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
// ������ ������ �� ��������� �����, ������� ����� � menuStrip
System::Void DBLibClient::FindForEditForm::������������������������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
// ������ ������ �� ��������� �����
System::Void DBLibClient::FindForEditForm::BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
// ���������� � ���� ������ ������� ��������������
System::Void DBLibClient::FindForEditForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}
// ���� ����������� ������ � ��������� �������
System::Void DBLibClient::FindForEditForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	System::String^ request = nameBookTextBox->Text;	// ������� ������ ��� ������
	System::String^ typeOfLit = choiceOfTypeBook->Text; // ��� ����������
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer();
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sRequest(cRequest); // ������ �� �������
	std::string sTypeOfLit(cTypeOfLit); // ��� ���������� �� ������� ����� ���������� �������
	std::vector <std::string> littleDB; // ������ ������ ��� ������ � �������
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease;
	std::string availability;
	std::string price;
	size_t i = 0;
	Admin admin;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("����������, ��������� ��� ����", "��������");
	else
		admin.searchByRequest(littleDB, sRequest, sTypeOfLit);
	// ������ ������� ����� ������� ������ �������
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	// ������� ������ � �������
	if (littleDB.size() != 0) {
		do {
			admin.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability, price);
			System::String^ SnameBook = gcnew String(nameBook.c_str());
			System::String^ SnameAutor = gcnew String(nameAutor.c_str());
			System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
			System::String^ Savailability = gcnew String(availability.c_str());
			System::String^ Sprice = gcnew String(price.c_str());

			dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability, Sprice);
			i++;
		} while (i < littleDB.size());
	}
	Marshal::FreeHGlobal((IntPtr)cRequest);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}
// ������� ������� ��� ����� 
System::Void DBLibClient::FindForEditForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ������ �� ����� ��� ������ ��������� ��������� ��������������� ���������� �������,	\
		���� ������������ ��� ������(�������� �����, ��� ������, ��� ������� �����; ������� � ����������)		\
		\n������: ����� � ���, �.�. ������� ��� ����� � ���, �.�. �������, 1865", "��������",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
}
// ���������� ��� ������ � ����������� �������
System::Void DBLibClient::FindForEditForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	setlocale(LC_ALL, "ru");
	Admin admin;
	std::vector <std::string> littleDB; 
	std::string nameBook;		// �������� �����
	std::string nameAutor;		// ��� ������
	std::string yearOfRelease;	// ��� ������� �����
	std::string availability;	// ���������� ����������� �����, � �������
	std::string price;
	bool flag = 0; // ������ �������� checkBox1, ������� ��������� ���������� �� ������ ����� � �������
	System::String^ typeOfLit = choiceOfTypeBook->Text;
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sTypeOfLit(cTypeOfLit); 
	size_t i = 0;
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	if (checkBox1->Checked == false)
		flag = 0;
	else if (checkBox1->Checked == true)
		flag = 1;
	if (choiceOfTypeBook->Text == "") MessageBox::Show("�������� ��� ���������� ��� �����������", "��������");
	// ��������� ��������� ������ �������� �� ����� � ����������� �����������
	else if (choiceOfTypeBook->Text == "�����������") {
		admin.showAllLines(littleDB, sTypeOfLit, flag); // ��������� � ������ littleDb, ��� �� ������� � �������
	}
	// ��������� ��������� ������ �������� �� ����� � �������������� �����������
	else if (choiceOfTypeBook->Text == "��������������") {
		admin.showAllLines(littleDB, sTypeOfLit, flag);
	}
	// ������� ��� ������ �� ���������� � �������
	if (littleDB.size() != 0) {
		do
		{
			// ��������� ������ �� ���������, ��� �������� � datagridview
			admin.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability, price);
			System::String^ SnameBook = gcnew String(nameBook.c_str());
			System::String^ SnameAutor = gcnew String(nameAutor.c_str());
			System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
			System::String^ Savailability = gcnew String(availability.c_str());
			System::String^ Sprice = gcnew String(price.c_str());
			dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability, Sprice);
			i++;
		} while (i < littleDB.size());
	}
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}
// ����� �� ���������
System::Void DBLibClient::FindForEditForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
// ������ �������������� �������
System::Void DBLibClient::FindForEditForm::EditEntryButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin admin;
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ��� ��������������, � ����� ������� ������ �������������", "������");
		return;
	}
	
	int indexLine = dataGridView1->SelectedRows[0]->Index; // ���������� ������ ��������� �����
	
	String^ typeOfLit = choiceOfTypeBook->Text;
	String^ nameBook = dataGridView1->Rows[indexLine]->Cells[0]->Value->ToString();
	String^ nameAutor = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();
	String^ yearOfRelease = dataGridView1->Rows[indexLine]->Cells[2]->Value->ToString();
	String^ availability = dataGridView1->Rows[indexLine]->Cells[3]->Value->ToString();
	String^ price = dataGridView1->Rows[indexLine]->Cells[4]->Value->ToString();

	
	char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
	char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(nameAutor).ToPointer();
	char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearOfRelease).ToPointer();
	char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(availability).ToPointer();
	char* cPrice = (char*)Marshal::StringToHGlobalAnsi(price).ToPointer();

	std::string sNameBook(cNameBook);
	std::string sAutorName(cAutorName);
	std::string sYearsOfRelease(cYearsOfRelease);
	std::string sAvailability(cAvailability);
	std::string sPrice(cPrice);
	
	std::string line = sNameBook + ", " + sAutorName + ", " + sYearsOfRelease + "; " + sAvailability + "; " + sPrice;
	// ��������� � ����� ��� ��������������
	editingWindowForm^ form = gcnew editingWindowForm(nameBook, nameAutor, yearOfRelease, availability, price, typeOfLit);
	
	form->ShowDialog();

	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
	Marshal::FreeHGlobal((IntPtr)cPrice);
}
// �������� ������ �� ���� ������
System::Void DBLibClient::FindForEditForm::deleteLineButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin admin;
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("�������� ���� ������ ��� ��������", "������");
		return;
	}
	// ����� ������ ��������� ������
	int indexLine = dataGridView1->SelectedRows[0]->Index;
	// ��������� ������
	String^ nameBook = dataGridView1->Rows[indexLine]->Cells[0]->Value->ToString();
	String^ nameAutor = dataGridView1->Rows[indexLine]->Cells[1]->Value->ToString();
	String^ yearOfRelease = dataGridView1->Rows[indexLine]->Cells[2]->Value->ToString();
	String^ availability = dataGridView1->Rows[indexLine]->Cells[3]->Value->ToString();
	String^ price = dataGridView1->Rows[indexLine]->Cells[4]->Value->ToString();

	char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
	char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(nameAutor).ToPointer();
	char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearOfRelease).ToPointer();
	char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(availability).ToPointer();
	char* cPrice = (char*)Marshal::StringToHGlobalAnsi(price).ToPointer();

	System::String^ typeOfLit = choiceOfTypeBook->Text;
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sTypeOfLit(cTypeOfLit);
	std::string sNameBook(cNameBook);
	std::string sAutorName(cAutorName);
	std::string sYearsOfRelease(cYearsOfRelease);
	std::string sAvailability(cAvailability);
	std::string sPrice(cPrice);

	std::string line = sNameBook + ", " + sAutorName + ", " + sYearsOfRelease + "; " + sAvailability + "; " + sPrice;
	if (choiceOfTypeBook->Text == "�����������") {
		admin.deleteLine(line, sTypeOfLit);
	}
	else if (choiceOfTypeBook->Text == "��������������") {
		admin.deleteLine(line, sTypeOfLit);
	}
	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
	Marshal::FreeHGlobal((IntPtr)cPrice);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
	MessageBox::Show("������ ������� �������.\n������� '�������� ��� ������', ��� �� ������� ���������.", "�������");
}
// ������ ����� �� ���������
System::Void DBLibClient::FindForEditForm::FindForEditForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}
Leaks _l;