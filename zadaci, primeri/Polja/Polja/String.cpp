#include "String.h"


String::String()
{
	size = 0;
	array = nullptr;
}


String::~String()
{
	if (array != nullptr)
		delete[]array;
}

String::String(int n)
{
	size = n;
	array = new char[size];
};

bool String::isEmpty()
{
	return (size != 0);
};

char* String::substring(int begining, int sizeOfsubstring)  //vraca podniz koji pocinje na poziciji begining i duzine je sizeOfsubstring
{
	if (begining + sizeOfsubstring > size)
		throw "Podniz je predugacak";
	char* temp = new char[sizeOfsubstring + 1];
	int i = 0;
	for (int j = begining; j < begining + sizeOfsubstring; j++)
		temp[i++] = array[j];
	temp[i] = '\0';
		return temp;

};

int String::indexing(char* substring)  //vraca prvu poziciju pojave podstringa
{
	int sizeOfsubstring = 0;
	while (substring[sizeOfsubstring] != '\0')
	{
		sizeOfsubstring++;
	}
	int i = 0;
	while (array[i] != substring[0])
	{
		i++;
	}
	if (i == size)
		return NULL;
	else
	{
		int LOC = i;
		int k = 1;
		while (k < sizeOfsubstring && array[i] == substring[k] && i < size)
		{
			k++;
			i++;
		}
		if (k == sizeOfsubstring)
			return LOC;
		else
			return NULL;
	}
}

void String::concatenation(char* substring1, char* substring2) //nadovezuje dva stringa
{
	int size1, size2;
	size1 = size2 = 0;
	delete[]array;
	while (substring1[size1] != '\0')
	{
		size1++;
	}
	while (substring2[size2] != '\0')
	{
		size2++;
	}
	size = size1 + size2 + 1;
	char* array = new char[size1 + size2 + 1];
	int i = 0;
	for (int i = 0; i < size1; i++)
		array[i] = substring1[i];
	for (int j = 0; j < size2; j++)
		array[i] = substring2[j];

}

int String::lenght()
{
	return size;
};

char* String::insert(int begin, char* substring) //begin je pozicija od koje je vrsi umetanje
{
	int size1 = 0;
	while (substring[size1] != '\0')
	{
		size1++;
	}
	char* temp = new char[size + 1];
	int sizeOftemp = 0;
	for (int i = 0; i < size; i++)
		temp[sizeOftemp] = array[i];
	delete[] array;
	array = new char[size + size1 + 1];
	size = size + size1 + 1;
	for (int i = 0; i < begin; i++)
		array[i] = temp[i];
	int k = 0;
	for (int i = begin; i < size1 + begin; i++)
		array[i] = temp[k++];
	for (int i = size1 + begin; i < size; i++)
		array[i] = temp[i];
	return array;
}

void String::replace(char* substing, char* replacement) //substring se menja replacement-om
{

}

void String::deleteSubstring(int begin, int sizeOfsubstring) //brisanje se vrsi od pozicije begin, a prisu se sizeOfsubstring karaktera
{

}

void String::output()
{
	for (int i = 0; i < size; i++)
		cout << array[i];
	cout << endl;
}

void String::input()
{
	cout << "Unesite zeljeni string" << endl;
	char s[100];
	cin >> s;
	int size1 = 0;
	while (s[size1] != '\0')
	{
		size1++;
	}
	size = size1;
	array = new char[size];
	for (int i = 0; i < size; i++)
		array[i] = s[i];

}
