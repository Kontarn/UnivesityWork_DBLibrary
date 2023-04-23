#include "pch.h"
#include "DBLibLibrary.h"

User::User()
{
	nameBook = DBG_NEW std::string;
	nameAutor = DBG_NEW std::string;
	yearsOfRelease = DBG_NEW std::string;
	availability = DBG_NEW std::string;
	littleDB = DBG_NEW std::vector <std::string>;
}
// Ищет похожие записи в выбранной БД
bool User::recordExistenceCheck(std::string inputText, std::string typeOfLit)
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
void User::splitEntry(std::string inpText, std::string& nameBook,
	std::string& nameAutor, std::string& yearOfRelease, std::string& availability)
{
	nameBook = "";
	nameAutor = "";
	yearOfRelease = "";
	availability = "";
	std::vector <char> InpTEXT;
	std::vector <char>::iterator POS;
	std::vector <char>::iterator POS1;
	char znak1{ ',' };
	char znak2{ ';' };
	for (int i = 0; i < inpText.size(); i++) {
		InpTEXT.push_back(inpText[i]);
	}
	// nameBook - название книги
	POS = find_if(InpTEXT.begin(), InpTEXT.end(), [&znak1](const char& a) {return a == znak1; });
	for (std::vector <char> ::iterator it = InpTEXT.begin(); it < POS; ++it)
		nameBook += *it;

	// nameAutor - ФИО автора
	POS1 = find(POS + 2, InpTEXT.end(), znak1);
	for (std::vector <char>::iterator it = POS + 2; it != POS1; ++it)
		nameAutor += *it;

	// yearOfRelease - год выпуска книги
	POS = find(POS1 + 2, InpTEXT.end(), znak2);
	for (std::vector <char>::iterator it = POS1 + 2; it != POS; ++it)
		yearOfRelease += *it;

	// availability - наличие в библиотеке
	for (std::vector <char>::iterator it = POS + 2; it != InpTEXT.end(); ++it)
		availability += *it;
}

// Ищет запись по введённому запросу
void User::searchByRequest(std::vector<std::string>* littleDB, std::string inpText, std::string typeOfLit)
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
// Добавляет все записи из файла контейнер для последующего вывода в таблицу
void User::showAllLines(std::vector<std::string>& littleDB, std::string typeOfLit,
	bool flag)
{
	std::string typeLit;
	if (typeOfLit == "Техническая")
		typeLit = TechLitDBname;
	else if (typeOfLit == "Художественная")
		typeLit = ArtLitDBname;
	std::ifstream fin;
	
	std::string str; // Нужна для временного хранения записи, перед добавленние в вектор
	
	if (typeOfLit != "Оба типа") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "")
					littleDB.push_back(str);
			}
		}
		fin.close();
	}
	else if (typeOfLit == "Оба типа") {
		fin.open(ArtLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					littleDB.push_back(str);
				}
			}
		}
		fin.close();
		fin.open(TechLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					littleDB.push_back(str);
				}
			}
		}
		fin.close();
	}
	// Убираем книги, которых нет в наличии
	if (flag == 1) {
		std::vector <std::string> ::iterator it = std::remove_if(littleDB.begin(), littleDB.end(), [](std::string a) {
			std::size_t pos;
			std::string avail; // наличие в библиотеке
			pos = a.find(";");
			avail = a;
			avail = avail.erase(0, pos + 2);
			return std::stoi(avail) == 0;
			});
		littleDB.erase(it, littleDB.end());
	}		
}

User::~User()
{
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
}