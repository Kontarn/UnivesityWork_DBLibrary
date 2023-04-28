#include "pch.h"
#include "DBLibLibrary.h"

Leaks::~Leaks() {
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}
Admin::Admin()
{
	size = 0;
}
// Добавляет запись в БД	Проверена
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

// Добавляет все записи из файла в контейнер для последующего вывода
void Admin::showAllLines(std::vector<std::string>& littleDB, std::string typeOfLit, bool flag)
{
	std::ifstream fin;
	std::string str, availability;
	size_t pos;
	std::vector <pair<int, string>> littledb;
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	//std::ifstream fin;
	//std::string str; // Нужна для временного хранения записи, перед добавленние в вектор
	fin.open(typeLit);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			if (str != "") {
				availability = str;
				pos = availability.find(';');
				availability.erase(0, pos + 2);
				littledb.push_back(make_pair(stoi(availability), str));
			}
		}
	}
	fin.close();
	// Убираем книги, которых нет в наличии, применяя алгоритм equal_range
	if (flag == 1) {
		// Отсортруем вектор по первому элементу пары
		sort(littledb.begin(), littledb.end(), [](const pair<int, string>& par, const pair<int, string>& par1) {
			return par.first < par1.first;
			});
		// result хранит интервал книг, которых нет в наличии
		pair <vector<pair<int, string>>::iterator, vector<pair<int, string>>::iterator> result;
		pair<int, string> par{ 0, "" }; // Нужно работы алгоритма equal_range
		result = equal_range(littledb.begin(), littledb.end(), par,
			[par](const pair<int, string>& par, const pair<int, string>& par1) {
				return par.first < par1.first;
			});
		// Удаляем все записи, которые имеют наличие 0
		littledb.erase(result.first, result.second);
	} 
	for (pair<int, string> i : littledb) {
		littleDB.push_back(i.second);
	}
}
//
//string** Admin::showAllLinesMass(string typeOfLit, bool flag)
//{
//	ifstream fin;
//	Admin admin;
//	string typeLit, str;
//	string nameBook, nameAutor, yearOfRelease, availability;
//	vector <string> littledb;
//	if (typeOfLit == "Техническая")
//		typeLit = TechLitDBname;
//	else if (typeOfLit == "Художественная")
//		typeLit = ArtLitDBname;
//	fin.open(typeLit);
//	while (!fin.eof()) {
//		getline(fin, str);
//		if (str != "") {
//			littledb.push_back(str);
//		}
//	}
//	fin.close();
//	
//	// Убираем книги, которых нет в наличии
//	if (flag == 1) {
//		std::vector <std::string> ::iterator it = std::remove_if(littledb.begin(),
//			littledb.end(), [](std::string a) {
//				std::size_t pos;
//				std::string avail; // наличие в библиотеке
//				pos = a.find(";");
//				avail = a;
//				avail = avail.erase(0, pos + 2);
//				return std::stoi(avail) == 0;
//			});
//		littledb.erase(it, littledb.end());
//	}
//	this->size = littledb.size();
//	string** littleDB = DBG_NEW string * [size];
//	for (int i = 0; i < size; i++)
//		littleDB[i] = DBG_NEW string[4];
//	for (int i = 0; i < size; i++) {
//		admin.splitEntry(littledb[i], nameBook, nameAutor, yearOfRelease, availability);
//		littleDB[i][0] = nameBook;
//		littleDB[i][1] = nameAutor;
//		littleDB[i][2] = yearOfRelease;
//		littleDB[i][3] = availability;
//	}
//	return littleDB;
//}

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
}
