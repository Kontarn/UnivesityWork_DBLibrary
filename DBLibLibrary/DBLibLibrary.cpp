#include "pch.h"
#include "DBLibLibrary.h"

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
}

