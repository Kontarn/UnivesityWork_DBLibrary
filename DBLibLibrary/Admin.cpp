#include "pch.h"
#include "DBLibLibrary.h"

Leaks::~Leaks() {
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}
Admin::Admin()
{
	size = 0;
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
}
