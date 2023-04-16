#include "pch.h"
#include "DBLibLibrary.h"

// ��������� �������� ������ �� ������� � �����
bool recordExistenceCheck(std::string nameBook, 
	std::string nameAutor, std::string yearsOfRelease, std::string availability)
{
	
	std::string StringToTest = nameBook + ", " + nameAutor + ", " + yearsOfRelease + "; " + availability;
	bool found = false;	//
	std::string stringForComparison; // ������ � ������� ����������
	int quantOfRepeat = 0; // ���������� ����������
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
		if (found == false) return found; // ���� � ����� ��� ���� ������
	}
	else {
		std::cout << "������ �������� �����" << std::endl;
	}
	fin.close();
}
// ������� ������ �� �� ����� ��� � ������� ����, ������ ������ ���������� ����� �������
bool recordExistenceCheck(std::string inputText, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	bool found = false;	//
	std::string stringForComparison; // ������ � ������� ����������
	int quantOfRepeat = 0; // ���������� ����������
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
		if (found == false) return found; // ���� � ����� ��� ���� ������
	}
	else {
		std::cout << "������ �������� �����" << std::endl;
	}
	fin.close();
}
// ��������� ���������� ������ ������ � ����������� ���������
DBLIBLIBRARY void splitEntry(std::string inpText, std::string& nameBook, 
	std::string& nameAutor, std::string& yearOfRelease, std::string& availability)
{
	std::string InpText=inpText;
	std::string INPText;
	std::size_t pos = 0;
	// nameBook - �������� �����
	pos = InpText.find(",", pos);
	INPText = inpText;
	INPText.erase(pos);
	nameBook = INPText;
	// nameAutor - ��� ������
	INPText = inpText;
	INPText.erase(0, pos + 2);
	pos = 0;
	pos = INPText.find(",", pos);
	INPText.erase(pos);
	nameAutor = INPText;
	// yearOfRelease - ��� ������� �����
	pos = 0;
	INPText = inpText;
	pos = INPText.find_last_of(",");
	INPText.erase(0, pos + 2);
	pos = 0;
	pos = INPText.find(";", pos);
	INPText.erase(pos);
	yearOfRelease = INPText;
	// availability - ������� ������ � ����������
	pos = 0;
	INPText = inpText;
	pos = INPText.find(";", pos);
	INPText.erase(0, pos + 2);
	availability = INPText;
}


