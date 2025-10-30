#include "FindForEditForm.h"

// Полный выход из программы
System::Void DBLibClient::FindForEditForm::выходИзПрограммыToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
// Кнопка выхода на начальный экран, которая лежит в menuStrip
System::Void DBLibClient::FindForEditForm::вернутсяНаНачальныйЭкранToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
// Кнопка выхода на начальный экран
System::Void DBLibClient::FindForEditForm::BackToStartMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	StartMenuForm^ form = gcnew StartMenuForm();
	this->Hide();
	form->Show();
}
// Возвращает в окно выбора способа редактирования
System::Void DBLibClient::FindForEditForm::BackToMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChoiceOfMethodEditForm^ form = gcnew ChoiceOfMethodEditForm();
	this->Hide();
	form->Show();
}
// Ищем определённую запись в выбранной таблице
System::Void DBLibClient::FindForEditForm::FindButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	System::String^ request = nameBookTextBox->Text;	// Введённй запрос для поиска
	System::String^ typeOfLit = choiceOfTypeBook->Text; // Тип литературы
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer();
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	std::string sRequest(cRequest); // Запрос на выборку
	std::string sTypeOfLit(cTypeOfLit); // Тип литературы из которой будет прозведена выборка
	std::vector <std::string> littleDB; // Хранит данные для вывода в таблицу
	std::string nameBook;
	std::string nameAutor;
	std::string yearOfRelease;
	std::string availability;
	std::string price;
	size_t i = 0;
	Admin admin;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("Пожалуйста, заполните все поля", "Внимание");
	else
		admin.searchByRequest(littleDB, sRequest, sTypeOfLit);
	// Чистим таблицу перед выводом данных вектора
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	// Выводим данные в таблицу
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
// Выводит правила для ввода 
System::Void DBLibClient::FindForEditForm::helpOfSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("При поиске по более чем одному параметру требуется соответствовать следующиму шаблону,	\
		ввод производится без скобок(Название книги, Имя автора, Год выпуска книги; наличие в библиотеке)		\
		\nПример: Война и мир, Л.Н. Толстой или Война и мир, Л.Н. Толстой, 1865", "Внимание",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information);
}
// Показывает все записи в определённой таблице
System::Void DBLibClient::FindForEditForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	setlocale(LC_ALL, "ru");
	Admin admin;
	std::vector <std::string> littleDB; 
	std::string nameBook;		// Название книги
	std::string nameAutor;		// Имя автора
	std::string yearOfRelease;	// Год выпуска книги
	std::string availability;	// Количество экземпляров книги, в наличии
	std::string price;
	bool flag = 0; // Хранит значение checkBox1, которые опредляет отображать ли только книги в наличии
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
	if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для отображения", "Внимание");
	// Заполняем контейнер только записями из файла с технической литературой
	else if (choiceOfTypeBook->Text == "Техническая") {
		admin.showAllLines(littleDB, sTypeOfLit, flag); // Добавляем в вектор littleDb, что бы вывести в таблицу
	}
	// Заполняем контейнер только записями из файла с художественной литературой
	else if (choiceOfTypeBook->Text == "Художественная") {
		admin.showAllLines(littleDB, sTypeOfLit, flag);
	}
	// Выводим все записи из контейнера в таблицу
	if (littleDB.size() != 0) {
		do
		{
			// Разбиваем строку на параметры, для передачи в datagridview
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
// Выход из программы
System::Void DBLibClient::FindForEditForm::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
// Кнопка редактирования записей
System::Void DBLibClient::FindForEditForm::EditEntryButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin admin;
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите поле для редактирования, а после нажмите кнопку редактировать", "Ошибка");
		return;
	}
	
	int indexLine = dataGridView1->SelectedRows[0]->Index; // Запоминает индекс выбранной стрки
	
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
	// Переходим в форму для редактирования
	editingWindowForm^ form = gcnew editingWindowForm(nameBook, nameAutor, yearOfRelease, availability, price, typeOfLit);
	
	form->ShowDialog();

	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
	Marshal::FreeHGlobal((IntPtr)cPrice);
}
// Удаление записи из базы данных
System::Void DBLibClient::FindForEditForm::deleteLineButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Admin admin;
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для удаления", "Ошибка");
		return;
	}
	// Узнаём индекс выбранной строки
	int indexLine = dataGridView1->SelectedRows[0]->Index;
	// Считываем данные
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
	if (choiceOfTypeBook->Text == "Техническая") {
		admin.deleteLine(line, sTypeOfLit);
	}
	else if (choiceOfTypeBook->Text == "Художественная") {
		admin.deleteLine(line, sTypeOfLit);
	}
	Marshal::FreeHGlobal((IntPtr)cNameBook);
	Marshal::FreeHGlobal((IntPtr)cAutorName);
	Marshal::FreeHGlobal((IntPtr)cYearsOfRelease);
	Marshal::FreeHGlobal((IntPtr)cAvailability);
	Marshal::FreeHGlobal((IntPtr)cPrice);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
	MessageBox::Show("Данные успешно удалены.\nНажмите 'Показать все записи', что бы увидеть изменения.", "Успешно");
}
// Полный выход из программы
System::Void DBLibClient::FindForEditForm::FindForEditForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}
Leaks _l;