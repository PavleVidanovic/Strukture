#pragma once
#include "iostream"
using namespace std;

class String
{
public:
	String();
	String(int n);
	~String();
	bool isEmpty();
	char* substring(int begining,int sizeOfsubstring);  //vraca podniz koji pocinje na poziciji begining i duzine je sizeOfsubstring
	int indexing(char* substring);  //vraca prvu poziciju pojave podstringa
	void concatenation(char* substring1,char* substring2); //nadovezuje dva stringa
	int lenght();
	char* insert(int begin,char* substring); //begin je pozicija od koje je vrsi umetanje
	void replace(char* substing,char* replacement); //substring se mena replacement-om
	void deleteSubstring(int begin,int sizeOfsubstring); //brisanje se vrsi od pozicije begin, a prisu se sizeOfsubstring karaktera
	void output();
	void input();

private:
	char* array;
	int size;
};

