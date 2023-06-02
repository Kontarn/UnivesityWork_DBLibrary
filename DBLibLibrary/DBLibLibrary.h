#pragma once
#define _CRTDBG_MAP_ALLOC
#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif
#include <crtdbg.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#define TechLitDBname	"..\\..\\������\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\������\\DBLibLibrary\\DBLibArt.txt"
using namespace std;
struct DBLIBLIBRARY Leaks {
	~Leaks();
};

class DBLIBLIBRARY User {
	vector <User*> NormalnayaDB;
	size_t size = 0;
	string line;
public:
	User();
	User(string line);
	int getSize();
	string getLine();
	// ���� ������� ������ � ��������� ��
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit);
	// ��������� ���������� ������ ������ � ����������� ���������
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	void showAllLinesMass(string**& littleDB, string typeOfLit, bool flag);
	// ���������� �� ���������� �������
	void sorting(string**& littleDB, string sortingMethod, size_t size);
	void searchByRequest(string**& littledb, string inpText, string typeOfLit);
	virtual ~User();
private:
	// ���������� �������� ���� �� ��������
	void sortNameBookAlphabet();
	// ���������� ������ ����, �� ��������
	void sortAutorNameAlphabet();
	// ���������� �� ���� �������, �� ����������� ��� ��������
	void sortYearOfReleaseAscending(std::string sortMethod);
};
class DBLIBLIBRARY Admin : public User {
	size_t size;
public:
	Admin();
	// ���������� ������� � ��
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability, std::string typeOfLit);
	// �������� ������ �� ��
	void deleteLine(std::string delLine, std::string typeOfLit);
	// �������������� �������
	void EditingNotation(std::string sourceString, std::string changedLine, 
		std::string typeOfLit);
	~Admin() override;
};
struct DBLIBLIBRARY LibInterface : public Admin {
	LibInterface();
	~LibInterface() override;
};