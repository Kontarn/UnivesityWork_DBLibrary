#include "pch.h"
#include "DBLibLibrary.h"

Leaks::~Leaks()
{
	_CrtCheckMemory();
}
Leaks _l;
TechLit::TechLit()
{
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
	littleDB = new std::vector <std::string>;
}
// Добавляем запись
bool TechLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability) {
	std::fstream fout;
	// Проверяем наличие записи в файле
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability) == false)
	{ // Если записи нет, то добавляем и возвращаем true
		fout.open(TechLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {
			fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
			fout.close();
		}
		else std::cout << "Ошибка открытия файла 'DBLibArt.txt'" << std::endl;
		return true;
	}
	// Если запись уже есть, то возвращаем false
	else return false;

}
// Ищет все записи, которые содержат введённую пользователем строку
void TechLit::searchByRequest(std::vector <std::string>* littleDB, std::string inpText)
{
	std::ifstream fin;
	fin.open(TechLitDBname);
	std::string stringForComparison; // Строка с которой сравнивают
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, stringForComparison);
			if (stringForComparison.find(inpText) != std::string::npos) {
				littleDB->push_back(stringForComparison);
			}
		}
	}
}
// Добавляет все записи файла txt в vector
void TechLit::showAllLines(std::vector<std::string>* littleDB)
{
	std::ifstream fin;
	std::string str; // Нужна для временного хранения записи, перед добавленние в вектор
	fin.open(TechLitDBname);
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, str);
			littleDB->push_back(str);
		}
	}
	fin.close();
}
// Ищет строку в файле
//char* TechLit::recordExistenceCheck(char* inputLine)
//{
//	std::ifstream fin;
//	std::string str; // Строка для сравнения
//	std::string InputLine(inputLine); 
//	bool found = false;
//	fin.open(TechLitDBname);
//	if (fin.is_open()) {
//		while (!fin.eof()) {
//			getline(fin, str);
//			found = str.find(InputLine) != std::string::npos;
//			if (found) {
//				return inputLine;
//				break;
//			}
//
//		}
//		if (found == false) {
//			return 0;
//		}
//	}
//	else {
//		std::cout << "Ошибка открытия файла" << std::endl;
//	}
//}
TechLit::~TechLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
}
