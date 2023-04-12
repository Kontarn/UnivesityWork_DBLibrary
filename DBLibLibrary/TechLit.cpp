#include "pch.h"
#include "DBLibLibrary.h"

TechLit::TechLit()
{
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
}
// ��������� ������
bool TechLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability) {
	std::fstream fout;
	// ��������� ������� ������ � �����
	if (recordExistenceCheck(nameBook, nameAutor, yearsOfRelease, availability) == false)
	{ // ���� ������ ���, �� ��������� � ���������� true
		fout.open(TechLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {
			fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
			fout.close();
		}
		else std::cout << "������ �������� ����� 'DBLibArt.txt'" << std::endl;
		return true;
	}
	// ���� ������ ��� ����, �� ���������� false
	else return false;

}
// ���� ������ � �����
//char* TechLit::recordExistenceCheck(char* inputLine)
//{
//	std::ifstream fin;
//	std::string str; // ������ ��� ���������
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
//		std::cout << "������ �������� �����" << std::endl;
//	}
//}
TechLit::~TechLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}
