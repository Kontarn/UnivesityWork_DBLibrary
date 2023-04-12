#pragma once

#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <fstream>
#define TechLitDBname	"..\\..\\������\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\������\\DBLibLibrary\\DBLibArt.txt"
//DBLIBLIBRARY_API void Test();

class DBLIBLIBRARY Library {
public:
	virtual bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) = 0;
	//virtual char* recordExistenceCheck(char* inputLine) = 0;
};
class DBLIBLIBRARY TechLit : public Library {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;			// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������

public:
	TechLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	//char* recordExistenceCheck(char* inputLine); 
	virtual ~TechLit();
};
class DBLIBLIBRARY ArtLit : public Library {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;			// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������
public:
	ArtLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	
	virtual ~ArtLit();
};

DBLIBLIBRARY bool recordExistenceCheck(std::string nameBook, std::string nameAutor,
	std::string yearsOfRelease, std::string availability); // �������� ������� ������ � ���� ������
DBLIBLIBRARY bool recordExistenceCheck(std::string inputText, std::string typeOfLit); // �������� ������� ������ � ���� ������