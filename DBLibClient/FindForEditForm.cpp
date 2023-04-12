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

System::Void DBLibClient::FindForEditForm::Help_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Если выбран способ поиска 'По автору и названию', то ввод должен производится по данному шаблону 'Фамилия И.О., Название книги'", "Правила ввода данных");
}

System::Void DBLibClient::FindForEditForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}

System::Void DBLibClient::FindForEditForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для поиска", "Внимание");
	else if (choiceOfTypeBook->Text == "Техническая") {

		/*else if (choiceOfWayFind->Text == "По автору и названию") {

			MessageBox::Show("Производится поиск по автору и названию из раздела технической литературы", "Успешно");
		}
		else if (choiceOfWayFind->Text == "По автору") {
			MessageBox::Show("Производится поиск по автору из раздела технической литературы", "ЗаглушОчка");
		}
		else if (choiceOfWayFind->Text == "По названию") {
			MessageBox::Show("Производится поиск по названию из раздела технической литературы", "ЗаглушОчка");
		}
		else if (choiceOfWayFind->Text == "По году") {
			MessageBox::Show("Производится поиск по году из раздела технической литературы", "ЗаглушОчка");
		}*/
	}
	else if (choiceOfTypeBook->Text == "Художественная") {
		//if (choiceOfWayFind->Text == "") MessageBox::Show("Выберите способ поиска", "Внимание");
		//else if (choiceOfWayFind->Text == "По автору и названию") {
		//	MessageBox::Show("Производится поиск по автору и названию из раздела художественной литературы", "ЗаглушОчка");
		//}
		//else if (choiceOfWayFind->Text == "По автору") {
		//	MessageBox::Show("Производится поиск по автору из раздела художественной литературы", "ЗаглушОчка");
		//}
		//else if (choiceOfWayFind->Text == "По названию") {
		//	MessageBox::Show("Производится поиск по названию из раздела художественной литературы", "ЗаглушОчка");
		//}
		//else if (choiceOfWayFind->Text == "По году") {
		//	MessageBox::Show("Производится поиск по году из раздела художественной литературы", "ЗаглушОчка");
		//}
	}
}
