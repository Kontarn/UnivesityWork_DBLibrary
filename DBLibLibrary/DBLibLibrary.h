#pragma once
#define _CRTDBG_MAP_ALLOC
#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#define TechLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLibArt.txt"


struct DBLIBLIBRARY Leaks {
	~Leaks();
};


class DBLIBLIBRARY Library {
public:
	// Функция производит поиск по запросу и возвращает все найденные записи
	virtual void searchByRequest(std::vector <std::string>* littleDB, std::string inpText, std::string typeOfLit) = 0;
	// Вывод все записи определённой базы данных
	virtual void showAllLines(std::vector <std::string>* littleDB, std::string typeOfLit) = 0;
	virtual bool recordExistenceCheck(std::string inputText, std::string typeOfLit) = 0;
};
class DBLIBLIBRARY Admin : public Library {
	std::string* nameBook;				// Название книги
	std::string* nameAutor;				// Автор
	std::string* yearsOfRelease;		// Год выпуска
	std::string* availability;			// Наличие в библиотеке
	std::vector <std::string>* littleDB;
public:
	Admin();
	bool recordExistenceCheck(std::string inputText, std::string typeOfLit); // Проверка наличия строки в базе данных
	// Разбивает строку inpText на парметры и присваивает прередаваемым переменным
	void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
		std::string& yearOfRelease, std::string& availability);
	// Добавление записей в БД
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability, std::string typeOfLit);
	// Поиск записей по запросу
	void searchByRequest(std::vector <std::string>* littleDB, 
		std::string inpText, std::string typeOfLit) override;
	// Показывает все записи
	void showAllLines(std::vector <std::string>* littleDB, std::string typeOfLit) override;
	// Удаление записи из БД
	void deleteLine(std::string delLine, std::string typeOfLit);
	// Редактирование записей
	void EditingNotation(std::string sourceString, std::string changedLine, 
		std::string typeOfLit);
	virtual ~Admin();
	
};
//class DBLIBLIBRARY User : public Admin {
//	
//};
// 