#include "pch.h"
#include "DBLibLibrary.h"

bool Library::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability, std::string typeOfLit) {
	std::fstream fout;
	// Проверяем наличие записи в файле
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability, typeOfLit) == false)
	{ // Если записи нет, то добавляем и возвращаем true
		fout.open(TechLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {
			std::cout << "Файл 'DBLibTech.txt' успешно открыт" << std::endl;

			fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
			fout.close();
		}
		else std::cout << "Ошибка открытия файла 'DBLibTech.txt'" << std::endl;
		return true;
	}
	// Если запись уже есть, то возвращаем false
	else return false;
}
