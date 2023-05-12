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
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
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
	//string** newLittleDB;
	size_t size;
public:
	User();
	//User(size_t size);
	int getSize();
	// ���� ������� ������ � ��������� ��
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit);
	// ��������� ���������� ������ ������ � ����������� ���������
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	void showAllLinesMass(string**& littleDB, string typeOfLit, bool flag);
	// ���������� �� ���������� �������
	void sortingMass(string**& littleDB, string sortingMethod, size_t size);
	void searchByRequestMass(string**& littleDB, string inpText, string typeOfLit);
	
	virtual ~User();
private:
	// ���������� �������� ���� �� ��������
	void sortNameBookAlphabet(vector <string>& littleDB);
	// ���������� ������ ����, �� ��������
	void sortAutorNameAlphabet(std::vector <std::string>& littleDB);
	// ���������� �� ���� �������, �� ����������� ��� ��������
	void sortYearOfReleaseAscending(std::vector <std::string>& littleDB, std::string sortMethod);
	//virtual void displayingAvailBook(vector <string>& littledb);
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