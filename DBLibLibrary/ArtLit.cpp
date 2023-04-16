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
	std::string& yearsOfRelease, std::string& availability) {
	std::fstream fout;
	// ��������� ������� ������ � �����
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability) == false)
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
			littleDB->push_back(str);
		}
	}
	fin.close();
}


ArtLit::~ArtLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}