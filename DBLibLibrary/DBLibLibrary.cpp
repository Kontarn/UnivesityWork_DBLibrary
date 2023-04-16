#include "pch.h"
#include "DBLibLibrary.h"

// Проверяет введённые данные на наличие в файле
bool recordExistenceCheck(std::string nameBook, 
	std::string nameAutor, std::string yearsOfRelease, std::string availability)
{
	
	std::string StringToTest = nameBook + ", " + nameAutor + ", " + yearsOfRelease + "; " + availability;
	bool found = false;	//
	std::string stringForComparison; // Строка с которой сравнивают
	int quantOfRepeat = 0; // Количество повторений
	std::ifstream fin;
	fin.open(ArtLitDBname);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, stringForComparison);
			found = stringForComparison.find(StringToTest) != std::string::npos;
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
// Функция делает то же самое что и функция выше, только данные передаются одной строкой
bool recordExistenceCheck(std::string inputText, std::string typeOfLit)
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
DBLIBLIBRARY void splitEntry(std::string inpText, std::string& nameBook, 
	std::string& nameAutor, std::string& yearOfRelease, std::string& availability)
{
	std::string InpText=inpText;
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


