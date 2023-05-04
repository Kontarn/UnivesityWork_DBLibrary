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
	size_t i = 0;
	User user;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("Пожалуйста, заполните все поля", "Внимание");
	else {
		user.searchByRequest(littleDB, sRequest, sTypeOfLit);
		// Сортирум определённым образом
		/*if (choiceOfSortingMethod->Text != "")
			user.sorting(littleDB, sSortingMethod);*/
	}
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	// Выводим данные в таблицу из littleDB
	if (littleDB.size() != 0) {
		do
		{
			// Разбиваем строку из вектора на параметры, для вывода в таблицу
			user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
			System::String^ SnameBook = gcnew String(nameBook.c_str());
			System::String^ SnameAutor = gcnew String(nameAutor.c_str());
			System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
			System::String^ Savailability = gcnew String(availability.c_str());
			dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
			i++;
		} while (i < littleDB.size());
	}
	Marshal::FreeHGlobal((IntPtr)cRequest);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}

System::Void DBLibClient::LibrarySearchForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	//setlocale(LC_ALL, "ru");
	//LibInterface libInter;
	//System::String^ typeOfLit = choiceOfTypeBook->Text;
	//char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	//std::string sTypeOfLit(cTypeOfLit);
	//bool flag = 0; // Хранит значение checkBox1, которые опредляет отображаение книг в наличии
	//string** littledb;
	//dataGridView1->Rows->Clear();
	//dataGridView1->Refresh();
	//if (checkBox1->Checked == false)
	//	flag = 0;
	//else if (checkBox1->Checked == true)
	//	flag = 1;
	//if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для отображения", "Внимание");
	//// Заполняем контейнер только записями из файла с технической литературой
	//else if (choiceOfTypeBook->Text == "Техническая") {
	//	littledb = libInter.showAllLinesMass(sTypeOfLit, flag);
	//}
	//// Заполняем контейнер только записями из файла с художественной литературой
	//else if (choiceOfTypeBook->Text == "Художественная") {
	//	littledb = libInter.showAllLinesMass(sTypeOfLit, flag);
	//}
	//size_t size = libInter.getSize();
	//if (size != 0) {
	//	for (size_t i = 0; i < size; i++) {
	//		System::String^ SnameBook = gcnew String(littledb[i][0].c_str());
	//		System::String^ SnameAutor = gcnew String(littledb[i][1].c_str());
	//		System::String^ SyearOfRelease = gcnew String(littledb[i][2].c_str());
	//		System::String^ Savailability = gcnew String(littledb[i][3].c_str());
	//		dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
	//	}
	//}
	//for (size_t i = 0; i < size; i++)
	//	delete[] littledb[i];
	//delete[] littledb;
	//Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
	//--------------------------------------------------------------------------------------------------------
	//setlocale(LC_ALL, "ru");
	//User user;
	//std::vector <std::string> littleDB;
	//std::string nameBook;
	//std::string nameAutor;
	//std::string yearOfRelease; // Год выпуска книги
	//std::string availability; // Количество определённой книги, в библиотеке
	//bool flag = 0; // Хранит значение checkBox1, которые опредляет отображать ли только книги в наличии
	//System::String^ typeOfLit = choiceOfTypeBook->Text; // Тип выбранной литературы
	//System::String^ sortingMethod = choiceOfSortingMethod->Text; // Способ соритровки
	//char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	//char* cSortingMethod = (char*)(Marshal::StringToHGlobalAnsi(sortingMethod)).ToPointer();
	//std::string sTypeOfLit(cTypeOfLit); // Тип литературы для отображения
	//std::string sSortingMethod(cSortingMethod); // Способ сортировки
	//size_t i = 0;
	//dataGridView1->Rows->Clear();
	//dataGridView1->Refresh();
	//if (checkBox1->Checked == false)
	//	flag = 0;
	//else if (checkBox1->Checked == true)
	//	flag = 1;

	//if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для поиска", "Внимание");
	//else {
	//	user.showAllLines(littleDB, sTypeOfLit, flag); // Добавляем в вектор littleDb, что бы вывести в таблицу
	//	// Сортирум определённым образом
	//	if (choiceOfSortingMethod->Text != "")
	//		user.sorting(littleDB, sSortingMethod);
	//}
	//// Выводим данные из вектора в datagridview
	//if (littleDB.size() != 0) {
	//	do
	//	{
	//		// Разбиваем строку на параметры для вывода в таблицу
	//		user.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
	//		System::String^ SnameBook = gcnew String(nameBook.c_str());
	//		System::String^ SnameAutor = gcnew String(nameAutor.c_str());
	//		System::String^ SyearOfRelease = gcnew String(yearOfRelease.c_str());
	//		System::String^ Savailability = gcnew String(availability.c_str());
	//		dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
	//		i++;
	//	} while (i < littleDB.size());
	//}
	//Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
	//- -----------------------------------------------------------------------------------------------------------
	setlocale(LC_ALL, "ru");
	LibInterface libInter;
	System::String^ typeOfLit = choiceOfTypeBook->Text;
	System::String^ sortingMethod = choiceOfSortingMethod->Text; // Способ соритровки
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	char* cSortingMethod = (char*)(Marshal::StringToHGlobalAnsi(sortingMethod)).ToPointer();
	std::string sTypeOfLit(cTypeOfLit);
	std::string sSortingMethod(cSortingMethod); // Способ сортировки
	bool flag = 0; // Хранит значение checkBox1, которые опредляет отображаение книг в наличии
	string** littledb;
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	if (checkBox1->Checked == false)
		flag = 0;
	else if (checkBox1->Checked == true)
		flag = 1;
	if (choiceOfTypeBook->Text == "") MessageBox::Show("Выберите тип литературы для отображения", "Внимание");
	// Заполняем контейнер только записями из файла с технической литературой
	else if (choiceOfTypeBook->Text == "Техническая" || choiceOfTypeBook->Text == "Художественная" || choiceOfTypeBook->Text == "Оба типа") {
		littledb = libInter.showAllLinesMass(sTypeOfLit, flag);
		size_t size = libInter.getSize();
		if (choiceOfSortingMethod->Text != "")
			libInter.sortingMass(littledb, sSortingMethod, size);
		// Заполняем контейнер только записями из файла с художественной литературой
		//else if (choiceOfTypeBook->Text == "Художественная") {
		//	littledb = libInter.showAllLinesMass(sTypeOfLit, flag);
		//}
		
		if (size != 0) {
			for (size_t i = 0; i < size; i++) {
				System::String^ SnameBook = gcnew String(littledb[i][0].c_str());
				System::String^ SnameAutor = gcnew String(littledb[i][1].c_str());
				System::String^ SyearOfRelease = gcnew String(littledb[i][2].c_str());
				System::String^ Savailability = gcnew String(littledb[i][3].c_str());
				dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
			}
		}
		for (size_t i = 0; i < size; i++)
			delete[] littledb[i];
		delete[] littledb;
	}
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}

System::Void DBLibClient::LibrarySearchForm::LibrarySearchForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Application::Exit();
}
