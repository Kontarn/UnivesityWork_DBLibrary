#include "AddElementsToDBForm.h"



System::Void DBLibClient::AddElementsToDBForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Шаблон по которому нужно вводить данные для добавления: Фамилия И.О., Название, Год выпуска; наличие");
}

System::Void DBLibClient::AddElementsToDBForm::BackButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::AddElementsToDBForm::toStartButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::AddElementsToDBForm::выходИзПрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::AddElementsToDBForm::выходНаНачальныйЭкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::AddElementsToDBForm::AddDataButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ nameBook = nameBookTextBox->Text;
	System::String^ AutorName = AutorNameTextBox->Text;
	System::String^ yearsOfRelease = yearOfReleaseTextBox->Text;
	System::String^ Availability = AvailabilityTextBox->Text;
	System::String^ typeOfLit = typeBookComboBox->Text;
	char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
	char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(AutorName).ToPointer();
	char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearsOfRelease).ToPointer();
	char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(Availability).ToPointer();
	char* cTypeOfLit = (char*)Marshal::StringToHGlobalAnsi(typeOfLit).ToPointer();
	std::string sNameBook(cNameBook);
	std::string sAutorName(cAutorName);
	std::string sYearsOfRelease(cYearsOfRelease);
	std::string sAvailability(cAvailability);
	std::string sTypeOfLit(cTypeOfLit);

	if (typeBookComboBox->Text == "Техническая") {
		TechLit Tlit;
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" 
			|| yearOfReleaseTextBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка");
		}
		else {

			if (Tlit.addLine(sNameBook, sAutorName, sYearsOfRelease, sAvailability, sTypeOfLit) == true) {
				MessageBox::Show("Данные добавлены в раздел технические", "Успешно");
			}
			else {
				MessageBox::Show("Запись уже существует, введите другую", "Ошибка");
			}
		}
	}
	else if (typeBookComboBox->Text == "Художественная") {
		ArtLit Alit;
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" 
			|| yearOfReleaseTextBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка");
		}
		else {
			if (Alit.addLine(sNameBook, sAutorName, sYearsOfRelease, sAvailability, sTypeOfLit) == true) {
				MessageBox::Show("Данные добавлены в раздел художественные", "Успешно");
			}
			else {
				MessageBox::Show("Запись уже существует, введите другую", "Ошибка");
			}
			
		}
	}
	else MessageBox::Show("Тип добавляемой литературы не выбран", "Ошибка");
	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
}


