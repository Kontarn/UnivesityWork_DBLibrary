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

#define TechLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLibArt.txt"
using namespace std;
struct DBLIBLIBRARY Leaks {
	~Leaks();
};

class DBLIBLIBRARY User {
	int size;
public:
	User();
	int getSize();
	// Функция производит поиск по запросу и возвращает все найденные записи
	//void searchByRequest(std::vector <std::string>& littleDB, std::string inpText, std::string typeOfLit);

	// Вывод все записи определённой базы данных
	/*virtual void showAllLines(std::vector <std::string>& littleDB, std::string typeOfLit,
		bool flag);*/
	
	// Ищет похожие записи в выбранной БД
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit);
	// Разрезает полученную запись данных и присваивает атрибутам
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	// Сортировка по выбранному способу
	//void sorting(vector <string>& littleDB, std::string sortingMethod);

	// --------------------Код под новые требования--------------------------------------------------------
	void showAllLinesMass(string**& littleDB, string typeOfLit, bool flag);
	void sortingMass(string**& littleDB, string sortingMethod, size_t size);
	void searchByRequestMass(string**& littleDB, string inpText, string typeOfLit);
	
	~User();
private:
	// Сортировка названия книг по алфавиту
	void sortNameBookAlphabet(vector <string>& littleDB);

	// Сортировка автора книг, по алфавиту
	void sortAutorNameAlphabet(std::vector <std::string>& littleDB);
	// Соритровка по году выпуска, по возрастанию или убыванию
	void sortYearOfReleaseAscending(std::vector <std::string>& littleDB, std::string sortMethod);
	//virtual void displayingAvailBook(vector <string>& littledb);
};
class DBLIBLIBRARY Admin : public User {
	//std::vector <std::string>* littleDB;
	
	size_t size;
public:
	Admin();
	// Добавление записей в БД
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability, std::string typeOfLit);
	// Добавляет записи в контейнер для последующего вывода в таблицу
	//void showAllLines(std::vector <std::string>& littleDB, std::string typeOfLit, bool flag) override;
	//void showAllLinesMass(string**& littleDB, string typeOfLit, bool flag) override;
	// Удаление записи из БД
	void deleteLine(std::string delLine, std::string typeOfLit);
	// Редактирование записей
	void EditingNotation(std::string sourceString, std::string changedLine, 
		std::string typeOfLit);
	~Admin();
};
struct DBLIBLIBRARY LibInterface : public Admin {
	LibInterface();
	~LibInterface();
};