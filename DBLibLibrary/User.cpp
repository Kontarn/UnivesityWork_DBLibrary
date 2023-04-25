#include "pch.h"
#include "DBLibLibrary.h"

User::User()
{
	nameBook = DBG_NEW std::string;
	nameAutor = DBG_NEW std::string;
	yearsOfRelease = DBG_NEW std::string;
	availability = DBG_NEW std::string;
	littleDB = DBG_NEW std::vector <std::string>;
}
// ���� ������� ������ � ��������� ��
bool User::recordExistenceCheck(std::string inputText, std::string typeOfLit)
{
	std::string typeLit;
	std::string otherTypeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else if (typeOfLit == "��������������") { typeLit = ArtLitDBname; }
	std::set <std::string> TechLit;
	std::set <std::string> ArtLit;
	bool found = false;	// 
	std::string stringForComparison; // ������ � ������� ����������
	int quantOfRepeat = 0; // ���������� ����������
	std::ifstream fin;
	fin.open(TechLitDBname);
	while (!fin.eof()) {
		getline(fin, stringForComparison);
		TechLit.insert(stringForComparison);

	} int TechRes = count_if(TechLit.begin(), TechLit.end(), [inputText](const std::string& a) { return !(a.find(inputText)); });
	fin.close();
	fin.open(ArtLitDBname);
	while (!fin.eof()) {
		getline(fin, stringForComparison);
		ArtLit.insert(stringForComparison);
	} int ArtRes = count_if(ArtLit.begin(), ArtLit.end(), [inputText](const std::string& a) { return !(a.find(inputText)); });
	fin.close();
	if (TechRes == 0 && ArtRes == 0) {
		return false;
	}
	else return true;
}
// ��������� ���������� ������ ������ � ����������� ���������
void User::splitEntry(std::string inpText, std::string& nameBook,
	std::string& nameAutor, std::string& yearOfRelease, std::string& availability)
{
	nameBook = "";
	nameAutor = "";
	yearOfRelease = "";
	availability = "";
	std::vector <char> InpTEXT;
	std::vector <char>::iterator POS;
	std::vector <char>::iterator POS1;
	char znak1{ ',' };
	char znak2{ ';' };
	for (int i = 0; i < inpText.size(); i++) {
		InpTEXT.push_back(inpText[i]);
	}
	// nameBook - �������� �����
	POS = find_if(InpTEXT.begin(), InpTEXT.end(), [&znak1](const char& a) {return a == znak1; });
	for (std::vector <char> ::iterator it = InpTEXT.begin(); it < POS; ++it)
		nameBook += *it;

	// nameAutor - ��� ������
	POS1 = find(POS + 2, InpTEXT.end(), znak1);
	for (std::vector <char>::iterator it = POS + 2; it != POS1; ++it)
		nameAutor += *it;

	// yearOfRelease - ��� ������� �����
	POS = find(POS1 + 2, InpTEXT.end(), znak2);
	for (std::vector <char>::iterator it = POS1 + 2; it != POS; ++it)
		yearOfRelease += *it;

	// availability - ������� � ����������
	for (std::vector <char>::iterator it = POS + 2; it != InpTEXT.end(); ++it)
		availability += *it;
}
// �������� ���������� ������ ����������
void User::sorting(std::vector<std::string>& littleDB, std::string sortingMethod)
{
	if (sortingMethod == "�� ��������, �� ��������")
		sortNameBookAlphabet(littleDB);
	else if (sortingMethod == "�� ������, �� ��������")
		sortAutorNameAlphabet(littleDB);
	else if (sortingMethod == "�� ����, � ������� �����������")
		sortYearOfReleaseAscending(littleDB, sortingMethod);
	else if (sortingMethod == "�� ����, � ������� ��������")
		sortYearOfReleaseAscending(littleDB, sortingMethod);
}
// ���� ������ �� ��������� �������
void User::searchByRequest(std::vector<std::string>& littleDB, std::string inpText, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	
	std::string stringForComparison; // ������ � ������� ����������
	if (typeOfLit != "��� ����") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				if (stringForComparison.find(inpText) != std::string::npos) {
					littleDB.push_back(stringForComparison);
				}
			}
		}
		fin.close();
	}
	else if (typeOfLit == "��� ����") {
		fin.open(TechLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				if (stringForComparison.find(inpText) != std::string::npos) {
					littleDB.push_back(stringForComparison);
				}
			}
		}
		fin.close();
		fin.open(ArtLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				if (stringForComparison.find(inpText) != std::string::npos) {
					littleDB.push_back(stringForComparison);
				}
			}
		}
		fin.close();
	}
}
// ��������� ��� ������ �� ����� ��������� ��� ������������ ������ � �������
void User::showAllLines(std::vector<std::string>& littleDB, std::string typeOfLit, bool flag)
{
	std::string typeLit;
	if (typeOfLit == "�����������")
		typeLit = TechLitDBname;
	else if (typeOfLit == "��������������")
		typeLit = ArtLitDBname;
	std::ifstream fin;
	std::vector <std::string> littleDB1, littleDB2;
	std::string str; // ����� ��� ���������� �������� ������, ����� ����������� � ������
	
	if (typeOfLit != "��� ����") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "")
					littleDB.push_back(str);
			}
		}
		fin.close();
	}
	else if (typeOfLit == "��� ����") {
		fin.open(ArtLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					littleDB1.push_back(str);
				}
			}
		}
		fin.close();
		fin.open(TechLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					littleDB2.push_back(str);
				}
			}
		}
		fin.close();
		std::vector <std::string> littledb(littleDB1.size() + littleDB2.size());

		std::sort(littleDB1.begin(), littleDB1.end());
		std::sort(littleDB2.begin(), littleDB2.end());
		std::set_union(littleDB1.begin(), littleDB1.end(),
			littleDB2.begin(), littleDB2.end(), littledb.begin());
		for (std::string i : littledb) {
			littleDB.push_back(i);
		}
	}
	// ������� �����, ������� ��� � �������
	if (flag == 1) {
			std::vector <std::string> ::iterator it = std::remove_if(littleDB.begin(), littleDB.end(), [](std::string a) {
				std::size_t pos;
				std::string avail; // ������� � ����������
				pos = a.find(";");
				avail = a;
				avail = avail.erase(0, pos + 2);
				return std::stoi(avail) == 0;
				});
			littleDB.erase(it, littleDB.end());	

	}
}
// ���������� �������� ���� �� ��������
void User::sortNameBookAlphabet(std::vector<std::string>& littleDB)
{
	sort(littleDB.begin(), littleDB.end());
}
// ���������� ������ ����, �� ��������
void User::sortAutorNameAlphabet(std::vector<std::string>& littleDB)
{
	sort(littleDB.begin(), littleDB.end(), [](const std::string& par, const std::string& par1) {
		size_t pos, pos1;
		std::vector <char> parVect, par1Vect;
		std::string nameAutor, nameAutor1;
		nameAutor = par;
		pos = nameAutor.find(',');
		nameAutor.erase(0, pos + 2);
		pos1 = nameAutor.find_last_of(',');
		nameAutor.erase(pos1);
		nameAutor1 = par1;
		pos = nameAutor1.find(',');
		nameAutor1.erase(0, pos + 2);
		pos1 = nameAutor1.find_last_of(',');
		nameAutor1.erase(pos1);
		return nameAutor < nameAutor1;
		});
}
// ���������� �� ���� �������, �� ����������� ��� ��������
void User::sortYearOfReleaseAscending(std::vector<std::string>& littleDB, std::string sortMethod)
{
	sort(littleDB.begin(), littleDB.end(), [&sortMethod](const std::string& par, const std::string& par1) {
		size_t pos, pos1;
		std::vector <char> parVect, par1Vect;
		std::string yearOfRelease, yearOfRelease1;
		yearOfRelease = par;
		pos = yearOfRelease.find_last_of(',');
		yearOfRelease.erase(0, pos + 2);
		pos1 = yearOfRelease.find(';');
		yearOfRelease.erase(pos1);
		yearOfRelease1 = par1;
		pos = yearOfRelease1.find_last_of(',');
		yearOfRelease1.erase(0, pos + 2);
		pos1 = yearOfRelease1.find(';');
		yearOfRelease1.erase(pos1);
		if (sortMethod == "�� ����, � ������� �����������")
			return stoi(yearOfRelease) < stoi(yearOfRelease1);
		else if (sortMethod == "�� ����, � ������� ��������")
			return stoi(yearOfRelease) > stoi(yearOfRelease1);
		});
}

User::~User()
{
	delete nameAutor;
	delete nameBook;
	delete yearsOfRelease;
	delete availability;
	delete littleDB;
}