#include "pch.h"
#include "DBLibLibrary.h"



Leaks::~Leaks() {
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}
Admin::Admin()
{
	nameBook = DBG_NEW std::string;
	nameAutor = DBG_NEW std::string;
	yearsOfRelease = DBG_NEW std::string;
	availability = DBG_NEW std::string;
	littleDB = DBG_NEW std::vector <std::string>;
}
// ��������� ������ � ��
bool Admin::addLine(std::string& nameBook, std::string& nameAutor, 
	std::string& yearsOfRelease, std::string& availability, std::string typeOfLit)
{
	
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::fstream fout;
	std::string line = nameBook + ", " + nameAutor + ", " + yearsOfRelease + "; " + availability; // �������� ������
	
	// ��������� ������� ������ � �����
	if (recordExistenceCheck(line, typeOfLit) == false)
	{ // ���� ������ ���, �� ��������� � ���������� true
		fout.open(typeLit, std::fstream::in | std::fstream::out | std::fstream::app);
		if (fout.is_open()) {

			fout << line << "\n";
			fout.close();
		}
		return true;
	}
	// ���� ������ ��� ����, �� ���������� false
	else return false;
}

// ��������� ��� ������ �� ����� � ��������� ��� ������������ ������
void Admin::showAllLines(std::vector<std::string>* littleDB, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	std::string str; // ����� ��� ���������� �������� ������, ����� ����������� � ������
	fin.open(typeLit);
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

// ������� ������ �� �����
void Admin::deleteLine(std::string delLine, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::set <std::string> strSet;
	std::string getStrFile;
	std::fstream fs(typeLit, std::fstream::in | std::fstream::app);
	fs.seekg(0);
	// ��������� ��������� ����� ���������� ����� ����������
	while (!fs.eof()) {
		getline(fs, getStrFile);
		if (getStrFile.find(delLine)) {
			strSet.insert(getStrFile);
		}
	}
	fs.close();
	// ������ ���� ��� ����������
	std::fstream clear_file(typeLit, std::ios::out);
	clear_file << "";
	clear_file.close();
	fs.open(typeLit, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
	fs.close();
}
// �������������� ���� � ����������������� �������
void Admin::EditingNotation(std::string sourceString, std::string changedLine,
	std::string typeOfLit) // sourceString �������� ������, changedLine ��������� ������
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else if (typeOfLit == "��������������") {
		typeLit = ArtLitDBname;
	}
	std::set <std::string> strSet;
	std::string getStrFile; // ������ ������ ��������� �� �����
	std::fstream fs(typeLit, std::fstream::in | std::fstream::app);
	fs.seekg(0);
	// ��������� ��������� ����� ���������� ����� ����������
	while (!fs.eof()) {
		getline(fs, getStrFile);
		if (getStrFile.find(sourceString)) {
			strSet.insert(getStrFile);
		}
	}
	fs.close();
	// ������ ���� ��� ����������
	std::fstream clear_file(typeLit, std::ios::out);
	clear_file << "";
	clear_file.close();
	// �������������� ��� ��������� ������
	fs.open(typeLit, std::fstream::out | std::fstream::app);
	for (auto it = strSet.begin(); it != strSet.end(); ++it) {
		fs << *it << "\n";
	}
	// ��������� ��������� ������
	fs << changedLine << "\n";
	fs.close();
}

Admin::~Admin()
{
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
	
}
