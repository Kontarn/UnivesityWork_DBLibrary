#include "pch.h"
#include "DBLibLibrary.h"


Admin::Admin()
{
	nameBook = DBG_NEW std::string;
	nameAutor = DBG_NEW std::string;
	yearsOfRelease = DBG_NEW std::string;
	availability = DBG_NEW std::string;
	littleDB = DBG_NEW std::vector <std::string>;
}
Leaks::~Leaks() {
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}
// Ищет похожие записи в выбранной БД
bool Admin::recordExistenceCheck(std::string inputText, std::string typeOfLit)
{
	std::string typeLit;
	std::string otherTypeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else if (typeOfLit == "Художественная") { typeLit = ArtLitDBname; }
	std::set <std::string> TechLit;
	std::set <std::string> ArtLit;
	bool found = false;	// 
	std::string stringForComparison; // Строка с которой сравнивают
	int quantOfRepeat = 0; // Количество повторений
	std::ifstream fin;
	fin.open(TechLitDBname);
	while (!fin.eof()) {
		getline(fin, stringForComparison);
		TechLit.insert(stringForComparison);
		
	} int TechRes = count_if(TechLit.begin(), TechLit.end(), [inputText](const std::string& a) { return !(a.find(inputText)); });
	fin.close();
	fin.open(ArtLitDBname);
	while (!fin.eof()) {
		getline(fin, stringForComparison);
		ArtLit.insert(stringForComparison);
	} int ArtRes = count_if(ArtLit.begin(), ArtLit.end(), [inputText](const std::string& a) { return !(a.find(inputText)); });
	fin.close();
	if (TechRes == 0 && ArtRes == 0) {
		return false;
	}
	else return true;
}
// Разрезает полученную запись данных и присваивает атрибутам
void Admin::splitEntry(std::string inpText, std::string& nameBook,
	std::string& nameAutor, std::string& yearOfRelease, std::string& availability)
{
	std::string InpText = inpText;
	std::string INPText;
	std::size_t pos = 0;
	// nameBook - название книги
	pos = InpText.find(",", pos);
	INPText = inpText;
	INPText.erase(pos);
	nameBook = INPText;
	// nameAutor - ФИО автора
	INPText = inpText;
	INPText.erase(0, pos + 2);
	pos = 0;
	pos = INPText.find(",", pos);
	INPText.erase(pos);
	nameAutor = INPText;
	// yearOfRelease - год выпуска книги
	pos = 0;
	INPText = inpText;
	pos = INPText.find_last_of(",");
	INPText.erase(0, pos + 2);
	pos = 0;
	pos = INPText.find(";", pos);
	INPText.erase(pos);
	yearOfRelease = INPText;
	// availability - наличие книиги в библиотеке
	pos = 0;
	INPText = inpText;
	pos = INPText.find(";", pos);
	INPText.erase(0, pos + 2);
	availability = INPText;
}
// Добавляет запись в БД
bool Admin::addLine(std::string& nameBook, std::string& nameAutor, 
	std::string& yearsOfRelease, std::string& availability, std::string typeOfLit)
{
	
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::fstream fout;
	std::string line = nameBook + ", " + nameAutor + ", " + yearsOfRelease + "; " + availability; // введённая строка
	
	// Проверяем наличие записи в файле
	if (recordExistenceCheck(line, typeOfLit) == false)
	{ // Если записи нет, то добавляем и возвращаем true
		fout.open(typeLit, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {

			fout << line << "\n";
			fout.close();
		}
		return true;
	}
	// Если запись уже есть, то возвращаем false
	else return false;
}
// Ищет запись по введённому запросу
void Admin::searchByRequest(std::vector<std::string>* littleDB, std::string inpText, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	fin.open(typeLit);
	std::string stringForComparison; // Строка с которой сравнивают
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, stringForComparison);
			if (stringForComparison.find(inpText) != std::string::npos) {
				littleDB->push_back(stringForComparison);
			}
		}
	}
	fin.close();
}
// Добавляет все записи из файла в контейнер для последующего вывода
void Admin::showAllLines(std::vector<std::string>* littleDB, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	std::string str; // Нужна для временного хранения записи, перед добавленние в вектор
	fin.open(typeLit);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			if (str != "") {
				littleDB->push_back(str);
			}
		}
	}
	fin.close();
}
// Удаляет строку из файла
void Admin::deleteLine(std::string delLine, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::set <std::string> strSet;
	std::string getStrFile;
	std::fstream fs(typeLit, std::fstream::in | std::fstream::app);
	fs.seekg(0);
	// Заполняем контейнер всеми элементами кроме выбранного
	while (!fs.eof()) {
		getline(fs, getStrFile);
		if (getStrFile.find(delLine)) {
			strSet.insert(getStrFile);
		}
	}
	fs.close();
	// Чистим файл для перезаписи
	std::fstream clear_file(typeLit, std::ios::out);
	clear_file << "";
	clear_file.close();
	fs.open(typeLit, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
	fs.close();
}
// Перезаписывает файл с отредактированной записью
void Admin::EditingNotation(std::string sourceString, std::string changedLine,
	std::string typeOfLit) // sourceString исходная строка, changedLine изменённая строка
{
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else if (typeOfLit == "Художественная") {
		typeLit = ArtLitDBname;
	}
	std::set <std::string> strSet;
	std::string getStrFile; // Хранит строку считанную из файла
	std::fstream fs(typeLit, std::fstream::in | std::fstream::app);
	fs.seekg(0);
	// Заполняем контейнер всеми элементами кроме выбранного
	while (!fs.eof()) {
		getline(fs, getStrFile);
		if (getStrFile.find(sourceString)) {
			strSet.insert(getStrFile);
		}
	}
	fs.close();
	// Чистим файл для перезаписи
	std::fstream clear_file(typeLit, std::ios::out);
	clear_file << "";
	clear_file.close();
	// Перезаписываем без выбранной строки
	fs.open(typeLit, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
	// Добавляем изменённую строку
	fs << changedLine << "\n";
	fs.close();
}

Admin::~Admin()
{
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
	
}
