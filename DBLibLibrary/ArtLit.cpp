#include "pch.h"
#include "DBLibLibrary.h"


//Leaks::~Leaks()
//{
//	_CrtCheckMemory();
//}
//Leaks _l;
ArtLit::ArtLit() {
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
}

bool ArtLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability, std::string typeOfLit) {
	std::fstream fout;
	// Проверяем наличие записи в файле
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability, typeOfLit) == false)
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
// Ищет все записи, которые содержат введённую пользователем строку
void ArtLit::searchByRequest(std::vector <std::string>* littleDB, std::string inpText)
{
	std::ifstream fin;
	fin.open(ArtLitDBname);
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
// Добавляет все записи файла txt в vector
void ArtLit::showAllLines(std::vector<std::string>* littleDB)
{
	std::ifstream fin;
	std::string str; // Нужна для временного хранения записи, перед добавленние в вектор
	fin.open(ArtLitDBname);
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

void ArtLit::deleteLine(std::string delLine)
{
	std::set <std::string> strSet;
	std::string getStrFile;
	std::fstream fs(ArtLitDBname, std::fstream::in | std::fstream::app);
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
	std::fstream clear_file(ArtLitDBname, std::ios::out);
	clear_file << "";
	clear_file.close();
	fs.open(ArtLitDBname, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
	
}


ArtLit::~ArtLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}