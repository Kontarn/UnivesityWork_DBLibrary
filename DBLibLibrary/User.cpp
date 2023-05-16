#include "pch.h"
#include "DBLibLibrary.h"

User::User()
{
}
User::User(string line)
{
	this->line = line;
}
// ���������� ������ �������
int User::getSize()
{
	return size;
}
string User::getLine() {
	return line;
}

// ���� ������� ������ � ��������� ��    ���������
bool User::recordExistenceCheck(std::string inputText, std::string typeOfLit)
{
	std::string typeLit;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else if (typeOfLit == "��������������") { 
		typeLit = ArtLitDBname; 
	}
	std::set <std::string> TechLit;
	std::set <std::string> ArtLit;
	std::string stringForComparison; // ������ � ������� ����������
	std::ifstream fin;
	fin.open(TechLitDBname);
	while (!fin.eof()) {
		getline(fin, stringForComparison);
		TechLit.insert(stringForComparison);
	} 
	int TechRes = count_if(TechLit.begin(), TechLit.end(), [inputText](const std::string& a) { return !(a.find(inputText)); });
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
	std::vector <char> line; // ������ ������ �� �� ������
	vector<char>::iterator pos, pos1;
	char znak{ ',' };
	char znak1{ ';' };
	for (int i = 0; i < inpText.size(); i++) {
		line.push_back(inpText[i]);
	}
	// nameBook - �������� �����
	pos = find_if(line.begin(), line.end(), [&znak](const char& a) {return a == znak; });
	for (std::vector <char> ::iterator it = line.begin(); it < pos; ++it)
		nameBook += *it;

	// nameAutor - ��� ������
	pos1 = find(pos + 2, line.end(), znak);
	for (std::vector <char>::iterator it = pos + 2; it != pos1; ++it)
		nameAutor += *it;

	// yearOfRelease - ��� ������� �����
	pos = find(pos1 + 2, line.end(), znak1);
	for (std::vector <char>::iterator it = pos1 + 2; it != pos; ++it)
		yearOfRelease += *it;

	// availability - ������� � ����������
	for (std::vector <char>::iterator it = pos + 2; it != line.end(); ++it)
		availability += *it;
}
void User::searchByRequestMass(string**& littledb, string inpText, string typeOfLit) {
	std::string typeLit;
	LibInterface libInter;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	vector <string> littleDB;
	string nameBook, nameAutor, yearOfRelease, availability;
	std::string stringForComparison, stringToLower;
	// ������ � ������� ����������
	if (typeOfLit != "��� ����") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
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
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
					littleDB.push_back(stringForComparison);
				}
			}
		}
		fin.close();
		fin.open(ArtLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
					littleDB.push_back(stringForComparison);
				}
			}
		}
		fin.close();
	}
	
	this->size = littleDB.size();
	string** LittleDB = DBG_NEW string * [size];
	for (int i = 0; i < size; i++)
		LittleDB[i] = DBG_NEW string[4];
	for (int i = 0; i < size; i++) {
		libInter.splitEntry(littleDB[i], nameBook, nameAutor, yearOfRelease, availability);
		LittleDB[i][0] = nameBook;
		LittleDB[i][1] = nameAutor;
		LittleDB[i][2] = yearOfRelease;
		LittleDB[i][3] = availability;
	}
	littledb = LittleDB;

}

void User::searchByRequest(string**& littledb, string inpText, string typeOfLit)
{
	std::string typeLit;
	LibInterface libInter;
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	std::ifstream fin;
	//vector <string> littleDB;
	string nameBook, nameAutor, yearOfRelease, availability;
	std::string stringForComparison, stringToLower;
	
	// ������ � ������� ����������
	if (typeOfLit != "��� ����") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
					NormalnayaDB.push_back(new User(stringForComparison));
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
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
					NormalnayaDB.push_back(new User(stringForComparison));
				}
			}
		}
		fin.close();
		fin.open(ArtLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, stringForComparison);
				stringToLower = stringForComparison;
				transform(stringToLower.begin(), stringToLower.end(), stringToLower.begin(), tolower);
				transform(inpText.begin(), inpText.end(), inpText.begin(), tolower);
				if (stringToLower.find(inpText) != std::string::npos) {
					NormalnayaDB.push_back(new User(stringForComparison));
				}
			}
		}
		fin.close();
	}

	this->size = NormalnayaDB.size();
	string** LittleDB = DBG_NEW string * [size];
	for (int i = 0; i < size; i++)
		LittleDB[i] = DBG_NEW string[4];
	for (int i = 0; i < size; i++) {
		libInter.splitEntry(NormalnayaDB[i]->line, nameBook, nameAutor, yearOfRelease, availability);
		LittleDB[i][0] = nameBook;
		LittleDB[i][1] = nameAutor;
		LittleDB[i][2] = yearOfRelease;
		LittleDB[i][3] = availability;
	}
	littledb = LittleDB;
	for (User* i : NormalnayaDB)
		delete i;
}

// ��������� ������ ����� ��������, ��� ������������ ������ � �������
void User::showAllLinesMass(string**& littleDB, string typeOfLit, bool flag)
{
 	ifstream fin;
	User user;
	string typeLit;
	size_t pos;
	string nameBook, nameAutor, yearOfRelease, availability;
	std::vector <pair<int, string>> littleDBPair, littleDBPair1, littleDBPair2;
	std::string str; // ����� ��� ���������� �������� ������, ����� ����������� � ������
	if (typeOfLit == "�����������") {
		typeLit = TechLitDBname;
	}
	else typeLit = ArtLitDBname;
	if (typeOfLit != "��� ����") {
		fin.open(typeLit);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					availability = str;
					pos = availability.find(';');
					availability.erase(0, pos + 2);
					littleDBPair.push_back(make_pair(stoi(availability), str));
				}
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
					availability = str;
					pos = availability.find(';');
					availability.erase(0, pos + 2);
					littleDBPair1.push_back(make_pair(stoi(availability), str));
				}
			}
		}
		fin.close();
		fin.open(TechLitDBname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				getline(fin, str);
				if (str != "") {
					availability = str;
					pos = availability.find(';');
					availability.erase(0, pos + 2);
					littleDBPair2.push_back(make_pair(stoi(availability), str));
				}
			}
		}
		fin.close();
		vector <pair<int, string>> littledb(littleDBPair1.size() + littleDBPair2.size());
		// ���������� ������ �� ������� �������� ����
		sort(littleDBPair1.begin(), littleDBPair1.end(), [](const pair<int, string>& par, const pair<int, string>& par1) {
			return par.first < par1.first;
			});
		sort(littleDBPair2.begin(), littleDBPair2.end(), [](const pair<int, string>& par, const pair<int, string>& par1) {
			return par.first < par1.first;
			});
		auto result = set_union(littleDBPair1.begin(), littleDBPair1.end(),
			littleDBPair2.begin(), littleDBPair2.end(), littledb.begin());
		for (pair<int, string> i : littledb) {
			littleDBPair.push_back(make_pair(i.first, i.second));
		}
	}
	if (flag == 1) {
		// ���������� ������ �� ������� �������� ����
		sort(littleDBPair.begin(), littleDBPair.end(), [](const pair<int, string>& par, const pair<int, string>& par1) {
			return par.first < par1.first;
			});
		// result ������ �������� ����, ������� ��� � �������
		pair <vector<pair<int, string>>::iterator, vector<pair<int, string>>::iterator> result;
		pair<int, string> par{ 0, "" }; // ����� ������ ��������� equal_range
		result = equal_range(littleDBPair.begin(), littleDBPair.end(), par,
			[par](const pair<int, string>& par, const pair<int, string>& par1) {
				return par.first < par1.first;
			});
		// ������� ��� ������, ������� ����� ������� 0
		littleDBPair.erase(result.first, result.second);
	}
	this->size = littleDBPair.size();
	string** LittleDB = DBG_NEW string * [size];
	for (int i = 0; i < size; i++)
		LittleDB[i] = DBG_NEW string[4];

	for (int i = 0; i < size; i++) {
		user.splitEntry(littleDBPair[i].second, nameBook, nameAutor, yearOfRelease, availability);
		LittleDB[i][0] = nameBook;
		LittleDB[i][1] = nameAutor;
		LittleDB[i][2] = yearOfRelease;
		LittleDB[i][3] = availability;
	}
	littleDB = LittleDB;
}


// ���������� ������� ����������� �������
void User::sorting(string**& littleDB, string sortingMethod, size_t size) {
	User user;

	vector <string> littledb;
	string line;
	string nameBook, nameAutor, yearOfRelease, availability;
	for (int i = 0; i < size; i++) {
		line = "";
		line = littleDB[i][0] + ", " + littleDB[i][1] + ", " + littleDB[i][2] + "; " + littleDB[i][3];
		NormalnayaDB.push_back(new User(line));
	}
	if (sortingMethod == "�� ��������, �� ��������")
		sortNameBookAlphabet();
	else if (sortingMethod == "�� ������, �� ��������")
		sortAutorNameAlphabet();
	else if (sortingMethod == "�� ����, � ������� �����������")
		sortYearOfReleaseAscending(sortingMethod);
	else if (sortingMethod == "�� ����, � ������� ��������")
		sortYearOfReleaseAscending(sortingMethod);
	for (int i = 0; i < size; i++) {
		user.splitEntry(NormalnayaDB[i]->line, nameBook, nameAutor, yearOfRelease, availability);
		littleDB[i][0] = nameBook;
		littleDB[i][1] = nameAutor;
		littleDB[i][2] = yearOfRelease;
		littleDB[i][3] = availability;
	}
}
// ���������� �������� ���� �� ��������
void User::sortNameBookAlphabet() {
	sort(NormalnayaDB.begin(), NormalnayaDB.end(), [](User*& par, User*& par1) {
		return par->getLine() < par->getLine();
		});
}
// ���������� ������ ����, �� ��������
void User::sortAutorNameAlphabet()
{
	User user;
	
	sort(NormalnayaDB.begin(), NormalnayaDB.end(), [](User*& par, User*& par1) {
		size_t pos, pos1;
		std::vector <char> parVect, par1Vect;
		std::string nameAutor, nameAutor1;
		nameAutor = par->getLine();
		pos = nameAutor.find(',');
		nameAutor.erase(0, pos + 2);
		pos1 = nameAutor.find_last_of(',');
		nameAutor.erase(pos1);
		nameAutor1 = par1->getLine();
		pos = nameAutor1.find(',');
		nameAutor1.erase(0, pos + 2);
		pos1 = nameAutor1.find_last_of(',');
		nameAutor1.erase(pos1);
		return nameAutor < nameAutor1;
		});
}
// ���������� �� ���� �������, �� ����������� ��� ��������
void User::sortYearOfReleaseAscending(std::string sortMethod)
{
	sort(NormalnayaDB.begin(), NormalnayaDB.end(), [&sortMethod](User*& par, User*& par1) {
		size_t pos, pos1;
		std::vector <char> parVect, par1Vect;
		std::string yearOfRelease, yearOfRelease1;
		yearOfRelease = par->getLine();
		pos = yearOfRelease.find_last_of(',');
		yearOfRelease.erase(0, pos + 2);
		pos1 = yearOfRelease.find(';');
		yearOfRelease.erase(pos1);
		yearOfRelease1 = par1->getLine();
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
}