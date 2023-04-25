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
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;				// �����
	std::string* yearsOfRelease;			// ��� �������
	std::string* availability;			// ������� � ����������
	std::vector <std::string>* littleDB;
public:
	User();
	// ������� ���������� ����� �� ������� � ���������� ��� ��������� ������
	void searchByRequest(std::vector <std::string>& littleDB, std::string inpText, std::string typeOfLit);
	// ����� ��� ������ ����������� ���� ������
	virtual void showAllLines(std::vector <std::string>& littleDB, std::string typeOfLit,
		bool flag);
	// ���� ������� ������ � ��������� ��
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit);
	// ��������� ���������� ������ ������ � ����������� ���������
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	// ���������� �� ���������� �������
	void sorting(std::vector <std::string>& littleDB, std::string sortingMethod);
	// ���������� �������� ���� �� ��������
	void sortNameBookAlphabet(std::vector <std::string>& littleDB);
	// ���������� ������ ����, �� ��������
	void sortAutorNameAlphabet(std::vector <std::string>& littleDB);
	// ���������� �� ���� �������, �� ����������� ��� ��������
	void sortYearOfReleaseAscending(std::vector <std::string>& littleDB, std::string sortMethod);
	~User();
};
class DBLIBLIBRARY Admin : public User {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;				// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������
	std::vector <std::string>* littleDB;
public:
	Admin();
	// ���������� ������� � ��
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability, std::string typeOfLit);
	// ��������� ������ � ��������� ��� ������������ ������ � �������
	void showAllLines(std::vector <std::string>& littleDB, std::string typeOfLit, bool flag) override;
	// �������� ������ �� ��
	void deleteLine(std::string delLine, std::string typeOfLit);
	// �������������� �������
	void EditingNotation(std::string sourceString, std::string changedLine, 
		std::string typeOfLit);
	~Admin();
};
