#pragma once

#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <fstream>
#define TechLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\Курсач\\DBLibLibrary\\DBLibArt.txt"
//DBLIBLIBRARY_API void Test();

class DBLIBLIBRARY Library {
public:
	virtual bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) = 0;
	//virtual char* recordExistenceCheck(char* inputLine) = 0;
};
class DBLIBLIBRARY TechLit : public Library {
	std::string* nameBook;				// Название книги
	std::string* nameAutor;			// Автор
	std::string* yearsOfRelease;		// Год выпуска
	std::string* availability;			// Наличие в библиотеке

public:
	TechLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	//char* recordExistenceCheck(char* inputLine); 
	virtual ~TechLit();
};
class DBLIBLIBRARY ArtLit : public Library {
	std::string* nameBook;				// Название книги
	std::string* nameAutor;			// Автор
	std::string* yearsOfRelease;		// Год выпуска
	std::string* availability;			// Наличие в библиотеке
public:
	ArtLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	
	virtual ~ArtLit();
};

DBLIBLIBRARY bool recordExistenceCheck(std::string nameBook, std::string nameAutor,
	std::string yearsOfRelease, std::string availability); // Проверка наличия строки в базе данных
DBLIBLIBRARY bool recordExistenceCheck(std::string inputText, std::string typeOfLit); // Проверка наличия строки в базе данных