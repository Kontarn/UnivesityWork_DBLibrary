#include "FindForEditForm.h"


System::Void DBLibClient::FindForEditForm::выходИзПрограммыToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void DBLibClient::FindForEditForm::вернутсяНаНачальныйЭкранToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
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
	System::String^ request = nameBookTextBox->Text; // Введённые данные
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
	if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для поиска", "Внимание");
	else if (choiceOfTypeBook->Text == "Техническая") {
		TechLit tLit;
		tLit.searchByRequest(&littleDB, sRequest);
		splitEntry(littleDB[0], nameBook, nameAutor, yearOfRelease, availability);
		/*if (recordExistenceCheck(sNameBook, sTypeOfLit) == true) {
			EditDBForm^ form = gcnew EditDBForm();
			this->Hide();
			form->Show();
		}
		else {
			MessageBox::Show("Запись отсутствует в базе данных технической литературы \
либо выберите другую базу данных, либо добавьте запись", "Ошибка");
		}*/
	}
	else if (choiceOfTypeBook->Text == "Художественная") {
		//if (recordExistenceCheck(sNameBook, sTypeOfLit) == true) {
		//	EditDBForm^ form = gcnew EditDBForm();
		//	this->Hide();
		//	form->Show();
		//}
//		else {
//			MessageBox::Show("Запись отсутствует в базе данных художественной литературы \
//либо выберите другую базу данных, либо добавьте запись", "Ошибка");
//		}
	}
	Marshal::FreeHGlobal((IntPtr)cRequest);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}

System::Void DBLibClient::FindForEditForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("При поиске по более чем одному параметру требуется соответствовать следующиму шаблону		\
		ввод производится без скобок(Название книги, Имя автора, Год выпуска книги; наличие в библиотеке)		\
		\nПример: Война и мир, Л.Н. Толстой или Война и мир, Л.Н. Толстой, 1865", "Внимание");
}
