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
	// ��������� ������� ������ � �����
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability, typeOfLit) == false)
	{ // ���� ������ ���, �� ��������� � ���������� true
		fout.open(ArtLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {
			std::cout << "���� 'DBLibArt.txt' ������� ������" << std::endl;

			fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
			fout.close();
		}
		else std::cout << "������ �������� ����� 'DBLibArt.txt'" << std::endl;
		return true;
	}
	// ���� ������ ��� ����, �� ���������� false
	else return false;
}
// ���� ��� ������, ������� �������� �������� ������������� ������
void ArtLit::searchByRequest(std::vector <std::string>* littleDB, std::string inpText)
{
	std::ifstream fin;
	fin.open(ArtLitDBname);
	std::string stringForComparison; // ������ � ������� ����������
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
// ��������� ��� ������ ����� txt � vector
void ArtLit::showAllLines(std::vector<std::string>* littleDB)
{
	std::ifstream fin;
	std::string str; // ����� ��� ���������� �������� ������, ����� ����������� � ������
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
	// ��������� ��������� ����� ���������� ����� ����������
	while (!fs.eof()) {
		getline(fs, getStrFile);
		if (getStrFile.find(delLine)) {
			strSet.insert(getStrFile);
		}
	}
	//strSet.insert(delLine);
	fs.close();
	// ������ ���� ��� ����������
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