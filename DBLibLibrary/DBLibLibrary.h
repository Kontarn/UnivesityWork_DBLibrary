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

#define TechLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLibArt.txt"
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
	// Ищет похожие записи в выбранной БД
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit);
	// Разрезает полученную запись данных и присваивает атрибутам
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	void showAllLinesMass(string**& littleDB, string typeOfLit, bool flag);
	// Сортировка по выбранному способу
	void sorting(string**& littleDB, string sortingMethod, size_t size);
	void searchByRequest(string**& littledb, string inpText, string typeOfLit);
	virtual ~User();
private:
	// Сортировка названия книг по алфавиту
	void sortNameBookAlphabet();
	// Сортировка автора книг, по алфавиту
	void sortAutorNameAlphabet();
	// Соритровка по году выпуска, по возрастанию или убыванию
	void sortYearOfReleaseAscending(std::string sortMethod);
};
class DBLIBLIBRARY Admin : public User {
	size_t size;
public:
	Admin();
	// Добавление записей в БД
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability, std::string typeOfLit);
	// Удаление записи из БД
	void deleteLine(std::string delLine, std::string typeOfLit);
	// Редактирование записей
	void EditingNotation(std::string sourceString, std::string changedLine, 
		std::string typeOfLit);
	~Admin() override;
};
struct DBLIBLIBRARY LibInterface : public Admin {
	LibInterface();
	~LibInterface() override;
};