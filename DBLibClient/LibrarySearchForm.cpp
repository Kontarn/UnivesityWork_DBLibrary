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
    MessageBox::Show("При поиске по более чем одному параметру требуется соответствовать следующиму шаблону,	\
ввод производится без скобок (Название книги, Имя автора, Год выпуска книги)									\
\nПример: Война и мир, Л.Н. Толстой или Война и мир, Л.Н. Толстой, 1865", "Внимание");
}

System::Void DBLibClient::LibrarySearchForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	System::String^ request = nameBookTextBox->Text; // введённый запрос для поиска книги
	System::String^ typeOfLit = choiceOfTypeBook->Text; // Тип выбранной литературы
	System::String^ sortingMethod = choiceOfSortingMethod->Text; // Способ соритровки
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer(); 
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	char* cSortingMethod = (char*)(Marshal::StringToHGlobalAnsi(sortingMethod)).ToPointer();
	std::string sRequest(cRequest);
	std::string sTypeOfLit(cTypeOfLit);
	std::string sSortingMethod(cSortingMethod); // Способ сортировки
	std::vector <std::string> littleDB;
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease;
	std::string availability; // Наличие книги в библиотеке
	std::string price;
	size_t i = 0;
	User user;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("Пожалуйста, заполните все поля", "Внимание");
	else {
		user.searchByRequest(littleDB, sRequest, sTypeOfLit);
		// Сортирум определённым образом
		if (choiceOfSortingMethod->Text != "")
			user.sorting(littleDB, sSortingMethod);
	}
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	// Выводим данные в таблицу из littleDB
	if (littleDB.size() != 0) {
		do
		{
			// Разбиваем строку из вектора на параметры, для вывода в таблицу
			user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability, price);
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

System::Void DBLibClient::LibrarySearchForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	setlocale(LC_ALL, "ru");
	User user;
	std::vector <std::string> littleDB;
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease; // Год выпуска книги
	std::string availability; // Количество определённой книги, в библиотеке
	std::string price;

	bool flag = 0; // Хранит значение checkBox1, которые опредляет отображать ли только книги в наличии
	System::String^ typeOfLit = choiceOfTypeBook->Text; // Тип выбранной литературы
	System::String^ sortingMethod = choiceOfSortingMethod->Text; // Способ соритровки
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	char* cSortingMethod = (char*)(Marshal::StringToHGlobalAnsi(sortingMethod)).ToPointer();
	std::string sTypeOfLit(cTypeOfLit); // Тип литературы для отображения
	std::string sSortingMethod(cSortingMethod); // Способ сортировки
	size_t i = 0;
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	if (checkBox1->Checked == false)
		flag = 0;
	else if (checkBox1->Checked == true)
		flag = 1;

	if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для поиска", "Внимание");
	else {
		user.showAllLines(littleDB, sTypeOfLit, flag); // Добавляем в вектор littleDb, что бы вывести в таблицу
		// Сортирум определённым образом
		if (choiceOfSortingMethod->Text != "")
			user.sorting(littleDB, sSortingMethod);
	}
	// Выводим данные из вектора в datagridview
	if (littleDB.size() != 0) {
		do
		{
			// Разбиваем строку на параметры для вывода в таблицу
			user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability, price);
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

System::Void DBLibClient::LibrarySearchForm::LibrarySearchForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}
