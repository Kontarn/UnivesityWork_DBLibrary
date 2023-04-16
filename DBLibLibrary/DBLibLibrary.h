#pragma once

#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define TechLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLibArt.txt"



struct DBLIBLIBRARY Leaks {
	~Leaks();
};
class DBLIBLIBRARY Library {
public:
	virtual bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) = 0;
	// Функция производит поиск по запросу и возвращает все найденные записи
	virtual void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) = 0;
	virtual void showAllLines(std::vector <std::string>* littleDB) = 0;
	virtual void deleteLine(std::string delLine)=0;
};
class DBLIBLIBRARY TechLit : public Library {
	std::string* nameBook;				// Название книги
	std::string* nameAutor;				// Автор
	std::string* yearsOfRelease;		// Год выпуска
	std::string* availability;			// Наличие в библиотеке
	std::vector <std::string>* littleDB;
public:
	TechLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) override;
	void showAllLines(std::vector <std::string>* littleDB) override;
	void deleteLine(std::string delLine) override;
	virtual ~TechLit();
};
class DBLIBLIBRARY ArtLit : public Library {
	std::string* nameBook;				// Название книги
	std::string* nameAutor;				// Автор
	std::string* yearsOfRelease;		// Год выпуска
	std::string* availability;			// Наличие в библиотеке
public:
	ArtLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) override;
	void showAllLines(std::vector <std::string>* littleDb) override;
	void deleteLine(std::string delLine) override;
	virtual ~ArtLit();
};

DBLIBLIBRARY bool recordExistenceCheck(std::string nameBook, std::string nameAutor,
	std::string yearsOfRelease, std::string availability); // Проверка наличия строки в базе данных
DBLIBLIBRARY bool recordExistenceCheck(std::string inputText, std::string typeOfLit); // Проверка наличия строки в базе данных
DBLIBLIBRARY void splitEntry(std::string inpText, std::string& nameBook, std::string& nameAutor,
	std::string& yearOfRelease, std::string& availability);
