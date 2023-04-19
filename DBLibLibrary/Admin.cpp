#include "pch.h"
#include "DBLibLibrary.h"

Admin::Admin()
{
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
	littleDB = new std::vector <std::string>;
}


// Функция делает то же самое что и функция выше, только данные передаются одной строкой
bool Admin::recordExistenceCheck(std::string inputText, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "Техническая") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	bool found = false;	//
	std::string stringForComparison; // Строка с которой сравнивают
	int quantOfRepeat = 0; // Количество повторений
	std::ifstream fin;
	fin.open(typeLit);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, stringForComparison);
			found = stringForComparison.find(inputText) != std::string::npos;
			if (found == true) {
				return found;
				quantOfRepeat++;
				break;
			}
		}
		if (found == false) return found; // Если в файле нет этой записи
	}
	else {
		std::cout << "Ошибка открытия файла" << std::endl;
	}
	fin.close();
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
			std::cout << "Файл 'DBLibTech.txt' успешно открыт" << std::endl;

			fout << line << "\n";
			fout.close();
		}
		else std::cout << "Ошибка открытия файла 'DBLibTech.txt'" << std::endl;
		return true;
	}
	// Если запись уже есть, то возвращаем false
	else return false;
}

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
	//strSet.insert(delLine);
	fs.close();
	// Чистим файл для перезаписи
	std::fstream clear_file(typeLit, std::ios::out);
	clear_file << "";
	clear_file.close();
	fs.open(typeLit, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
}

Admin::~Admin()
{
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
}
