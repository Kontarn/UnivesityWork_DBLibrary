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
// ��������� ����������� ������ � ����


ArtLit::~ArtLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}