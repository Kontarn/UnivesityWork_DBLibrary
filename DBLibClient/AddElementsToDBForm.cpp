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
	
	
	if (typeBookComboBox->Text == "Техническая") {
		TechLit Tlit;
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" || yearOfReleaseTextBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка");
		}
		else {

			//System::String^ nameBook = nameBookTextBox->Text;
			//System::String^ AutorName = AutorNameTextBox->Text;
			//System::String^ yearsOfRelease = yearOfReleaseTextBox->Text;
			//System::String^ Availability = AvailabilityTextBox->Text;
			//char* cNameBook = (char*)Marshal::StringToHGlobalAnsi(nameBook).ToPointer();
			//char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(AutorName).ToPointer();
			//char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearsOfRelease).ToPointer();
			//char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(Availability).ToPointer();
			//Tlit.addLine(cNameBook, cAutorName, cYearsOfRelease, cAvailability);
			//Marshal::FreeHGlobal((IntPtr)cNameBook);
			//Marshal::FreeHGlobal((IntPtr)cAutorName);
			//Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
			//Marshal::FreeHGlobal((IntPtr)cAvailability);
			MessageBox::Show("Временно не работает", "Успешно");

		}

	}
	else if (typeBookComboBox->Text == "Художественная") {
		ArtLit Alit;
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" || yearOfReleaseTextBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка");
		}
		else {
			System::String^ nameBook = nameBookTextBox->Text;
			System::String^ AutorName = AutorNameTextBox->Text;
			System::String^ yearsOfRelease = yearOfReleaseTextBox->Text;
			System::String^ Availability = AvailabilityTextBox->Text;
			char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
			char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(AutorName).ToPointer();
			char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearsOfRelease).ToPointer();
			char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(Availability).ToPointer();
			std::string sNameBook(cNameBook);
			std::string sAutorName(cAutorName);
			std::string sYearsOfRelease(cYearsOfRelease);
			std::string sAvailability(cAvailability);
			Alit.addLine(sNameBook, sAutorName, sYearsOfRelease, sAvailability);
			Marshal::FreeHGlobal((IntPtr)cNameBook);
			Marshal::FreeHGlobal((IntPtr)cAutorName);
			Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
			Marshal::FreeHGlobal((IntPtr)cAvailability);
			MessageBox::Show("Данные добавлены в раздел художественные", "Успешно");
		}

	}
	else MessageBox::Show("Тип добавляемой литературы не выбран", "Ошибка");
}


