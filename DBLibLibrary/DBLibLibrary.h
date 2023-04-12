#pragma once
#ifdef DBLIBLIBRARY_EXPORTS
	#define DBLIBLIBRARY __declspec(dllexport)
#else
	#define DBLIBLIBRARY __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <fstream>
#define TechLitDBname	"..\\..\\DBLibLibrary\\DBLibLibrary\\DBLibTech.txt"
#define ArtLitDBname	"..\\..\\DBLibLibrary\\DBLibLibrary\\DBLitArt.txt"
//DBLIBLIBRARY_API void Test();

class DBLIBLIBRARY Library {
public:
	virtual void addLine(std::string& nameBook, std::string& nameAutor,
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
	void addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	//char* recordExistenceCheck(char* inputLine); // �������� ������� ������ � ���� ������
	virtual ~TechLit();
};
class DBLIBLIBRARY ArtLit : public Library {
	std::string* nameBook;				// �������� �����
	std::string* nameAutor;			// �����
	std::string* yearsOfRelease;		// ��� �������
	std::string* availability;			// ������� � ����������
public:
	ArtLit();
	void addLine(std::string& nameBook, std::string& nameAutor,
		std::string& yearsOfRelease, std::string& availability) override;
	bool recordExistenceCheck(std::string nameBook, std::string nameAutor,
		std::string yearsOfRelease, std::string availability);
	~ArtLit();
};
//DBLIBLIBRARY char* bufferStr(char* nameBook,
//	char* nameAutor, char* yearsOfRelease, char* available);