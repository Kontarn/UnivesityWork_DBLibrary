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
void TechLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability) {
	//char* StringToTest = bufferStr(nameBook, nameAutor, yearsOfRelease, availability); // ��� ����������� ������
	
	std::fstream fs;
	fs.open(TechLitDBname, std::fstream::in | std::fstream::out | std::fstream::app);
	if (fs.is_open()) {
		std::cout << "���� 'DBLibTech.txt' ������� ������" << std::endl;

		fs << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
		fs.close();
	}
	else std::cout << "������ �������� ����� 'DBLibTech.txt'" << std::endl;
	
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

ArtLit::ArtLit() {
	nameBook = new std::string;
	nameAutor = new std::string;
	yearsOfRelease = new std::string;
	availability = new std::string;
}

void ArtLit::addLine(std::string& nameBook, std::string& nameAutor,
	std::string& yearsOfRelease, std::string& availability) {
	
	
	std::fstream fout;
	fout.open(ArtLitDBname, std::fstream::out | std::fstream::app);
	if (fout.is_open()) {
		std::cout << "���� 'DBLibArt.txt' ������� ������" << std::endl;

		fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
		fout.close();
	}
	else std::cout << "������ �������� ����� 'DBLibArt.txt'" << std::endl;
	
	/*std::ofstream fout;
	fout.open(ArtLitDBname, std::ofstream::out | std::ofstream::app);
	if (fout.is_open()) {
		std::cout << "���� 'DBLibArt.txt' ������� ������" << std::endl;
		fout << nameBook << ", " << nameAutor << ", " << yearsOfRelease << "; " << availability << "\n";
		fout.close();
	}
	else std::cout << "������ �������� ����� 'DBLibTech.txt'" << std::endl;*/
}
// ��������� ����������� ������ � ����
bool ArtLit::recordExistenceCheck(std::string nameBook, std::string nameAutor,
	std::string yearsOfRelease, std::string availability)
{
	std::string StringToTest = nameBook + nameAutor + yearsOfRelease + availability;
	std::ifstream fin;
	bool found = false;
	std::string stringForComparison; // ������ � ������� �����������
	int quantOfRepeat = 0; // ���������� ����������
	fin.open(ArtLitDBname);
	if (fin.is_open()) {
		while (fin.eof()) {
			getline(fin, stringForComparison);
			found = stringForComparison.find(StringToTest) != std::string::npos;
			if (found == true) {
				return found;
				quantOfRepeat++;
				break;
			}
		}
		if (found == false) return found;
	} 
	else {
		return false;
	}
}


ArtLit::~ArtLit() {
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
}
// �������� ���������, �� ���������, �� ��� ������
//DBLIBLIBRARY char* bufferStr(char* nameBook, char* nameAutor, char* yearsOfRelease, char* available)
//{
//	std::string NameBook(nameBook);
//	std::string NameAutor(nameAutor);
//	std::string YearsOfRelease(yearsOfRelease);
//	std::string Available(available);
//	std::string inputLine = NameBook + NameAutor + YearsOfRelease + Available;
//	char* InputLine = new char[inputLine.size() + 1];
//	std::copy(inputLine.begin(), inputLine.end(), InputLine);
//	return InputLine;
//}
