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
#define TechLitDBname	"..\\..\\������\\DBLibLibrary\\DBLitTech.txt"
#define ArtLitDBname	"..\\..\\������\\DBLibLibrary\\DBLibArt.txt"

class DBLIBLIBRARY Library {
public:
	virtual bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) = 0;
	// ������� ���������� ����� �� ������� � ���������� ��� ��������� ������
	virtual void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) = 0;
};
class DBLIBLIBRARY TechLit : public Library {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;			// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������
	std::vector <std::string>* littleDB;
public:
	TechLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	virtual void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) override;
	virtual ~TechLit();
};
class DBLIBLIBRARY ArtLit : public Library {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;				// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������
public:
	ArtLit();
	bool addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	virtual void searchByRequest(std::vector <std::string>* littleDB, std::string inpText) override;
	virtual ~ArtLit();
};

DBLIBLIBRARY bool recordExistenceCheck(std::string nameBook, std::string nameAutor,
	std::string yearsOfRelease, std::string availability); // �������� ������� ������ � ���� ������
DBLIBLIBRARY bool recordExistenceCheck(std::string inputText, std::string typeOfLit); // �������� ������� ������ � ���� ������
DBLIBLIBRARY void splitEntry(std::string inpText, std::string& nameBook, std::string nameAutor,
	std::string& yearOfRelease, std::string& availability);
