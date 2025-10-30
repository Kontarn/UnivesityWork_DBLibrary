#include "AddElementsToDBForm.h"

System::Void DBLibClient::AddElementsToDBForm::HelpButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Шаблон по которому нужно вводить данные для добавления: Фамилия И.О., Название, Год выпуска; наличие", "Помощь",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
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
	System::String^ yearsOfRelease = yearOfReleaseComboBox->Text;
	System::String^ Availability = AvailabilityTextBox->Text;
	System::String^ price = priceTextBox->Text;
	System::String^ typeOfLit = typeBookComboBox->Text;
	char* cNameBook = (char*)(Marshal::StringToHGlobalAnsi(nameBook)).ToPointer();
	char* cAutorName = (char*)Marshal::StringToHGlobalAnsi(AutorName).ToPointer();
	char* cYearsOfRelease = (char*)Marshal::StringToHGlobalAnsi(yearsOfRelease).ToPointer();
	char* cAvailability = (char*)Marshal::StringToHGlobalAnsi(Availability).ToPointer();
	char* cPrice = (char*)Marshal::StringToHGlobalAnsi(price).ToPointer();
	char* cTypeOfLit = (char*)Marshal::StringToHGlobalAnsi(typeOfLit).ToPointer();
	std::string sNameBook(cNameBook);
	std::string sAutorName(cAutorName);
	std::string sYearsOfRelease(cYearsOfRelease);
	std::string sAvailability(cAvailability);
	std::string sPrice(cPrice);
	std::string sTypeOfLit(cTypeOfLit);
	Admin admin;
	if (typeBookComboBox->Text == "Техническая") {
		
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" 
			|| yearOfReleaseComboBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
		else {

			if (admin.addLine(sNameBook, sAutorName, sYearsOfRelease, sAvailability, sPrice, sTypeOfLit) == true) {
				MessageBox::Show("Данные добавлены в раздел технические", "Успешно",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
			
			else {
				MessageBox::Show("Запись уже существует, введите другую", "Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
			
		}
	}
	else if (typeBookComboBox->Text == "Художественная") {
		
		if (nameBookTextBox->Text == "" || AutorNameTextBox->Text == "" 
			|| yearOfReleaseComboBox->Text == "" || AvailabilityTextBox->Text == "") {
			MessageBox::Show("Данные введены не полностью!", "Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
		else {
			if (admin.addLine(sNameBook, sAutorName, sYearsOfRelease, sAvailability, sPrice, sTypeOfLit) == true) {
				MessageBox::Show("Данные добавлены в раздел художественные", "Успешно",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Запись уже существует, введите другую", "Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
			
		}
	}
	else MessageBox::Show("Тип добавляемой литературы не выбран", "Ошибка",
		MessageBoxButtons::OK,
		MessageBoxIcon::Error);
	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cPrice);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
}

System::Void DBLibClient::AddElementsToDBForm::AddElementsToDBForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}

System::Void DBLibClient::AddElementsToDBForm::AutorNameTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!(
		Char::IsLetter(e->KeyChar) || 
		Char::IsControl(e->KeyChar) || 
		e->KeyChar == '.' || 
		e->KeyChar == '-' || 
		Char::IsSeparator(e->KeyChar))
	) {
		e->Handled = true;
	}
}

System::Void DBLibClient::AddElementsToDBForm::AddElementsToDBForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	size_t currentYear = 2025;
	for (size_t i = 1900; i <= currentYear; i++) {
		yearOfReleaseComboBox->Items->Add(i);
	}
	yearOfReleaseComboBox->SelectedIndex = currentYear - 1900;
	
}

System::Void DBLibClient::AddElementsToDBForm::AvailabilityTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!(Char::IsControl(e->KeyChar) || Char::IsDigit(e->KeyChar))) {
		e->Handled = true;
	}
}

System::Void DBLibClient::AddElementsToDBForm::AvailabilityTextBox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	int avail = 0;
	if (int::TryParse(AvailabilityTextBox->Text, avail)) {
		if (avail < 0 || avail > 900) {
			MessageBox::Show("Значение должно быть в диапазоне от 0 до 900", "Ошибка", 
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			e->Cancel = true;
		}
	}
}

System::Void DBLibClient::AddElementsToDBForm::priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (!(Char::IsControl(e->KeyChar) || e->KeyChar == '.' || Char::IsDigit(e->KeyChar))) {
		e->Handled = true;
	}
}



