#include "pch.h"
#include "DBLibLibrary.h"

ArtLit::ArtLit() {
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
}

bool ArtLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability) {
	std::fstream fout;
	// Проверяем наличие записи в файле
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability) == false)
	{ // Если записи нет, то добавляем и возвращаем true
		fout.open(ArtLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {
			std::cout << "Файл 'DBLibArt.txt' успешно открыт" << std::endl;

			fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
			fout.close();
		}
		else std::cout << "Ошибка открытия файла 'DBLibArt.txt'" << std::endl;
		return true;
	}
	// Если запись уже есть, то возвращаем false
	else return false;
}
// проверяет присутствие записи в базе


ArtLit::~ArtLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}