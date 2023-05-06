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
	LibInterface libInter;
	System::String^ request = nameBookTextBox->Text; // введённый запрос для поиска книги
	System::String^ typeOfLit = choiceOfTypeBook->Text; // Тип выбранной литературы
	System::String^ sortingMethod = choiceOfSortingMethod->Text; // Способ соритровки
	char* cRequest = (char*)(Marshal::StringToHGlobalAnsi(request)).ToPointer(); 
	char* cTypeOfLit = (char*)(Marshal::StringToHGlobalAnsi(typeOfLit)).ToPointer();
	char* cSortingMethod = (char*)(Marshal::StringToHGlobalAnsi(sortingMethod)).ToPointer();
	std::string sRequest(cRequest);
	std::string sTypeOfLit(cTypeOfLit);

	std::string sSortingMethod(cSortingMethod); // Способ сортировки
	string** littleDB;
	size_t size;
	if (choiceOfTypeBook->Text == "" || nameBookTextBox->Text == "") MessageBox::Show("Пожалуйста, заполните все поля", "Внимание");
	else {
		libInter.searchByRequestMass(littleDB, sRequest, sTypeOfLit);
		size = libInter.getSize();
	}
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
	// Выводим данные в таблицу из littleDB
	if (size != 0) {
		for (int i = 0; i < size; i++)
		{
			// Разбиваем строку из вектора на параметры, для вывода в таблицу
			System::String^ SnameBook = gcnew String(littleDB[i][0].c_str());
			System::String^ SnameAutor = gcnew String(littleDB[i][1].c_str());
			System::String^ SyearOfRelease = gcnew String(littleDB[i][2].c_str());
			System::String^ Savailability = gcnew String(littleDB[i][3].c_str());
			dataGridView1->Rows->Add(SnameBook, SnameAutor, SyearOfRelease, Savailability);
		}
	}
	for (int i = 0; i < size; i++) {
		delete[] littleDB[i];
	}
	delete[] littleDB;
	Marshal::FreeHGlobal((IntPtr)cRequest);
	Marshal::FreeHGlobal((IntPtr)cTypeOfLit);
}

System::Void DBLibClient::LibrarySearchForm::ShowAllLinesButton_Click(System::Object^ sender, System::EventArgs^ e)
{
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
		libInter.showAllLinesMass(littledb, sTypeOfLit, flag);
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
