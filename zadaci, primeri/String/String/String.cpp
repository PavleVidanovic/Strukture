#pragma once
#include "iostream"
using namespace std;

int lenght(char* c)
{
	int size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return size;
}

bool isEmpty(char* c)
{
	return lenght(c);
}

char* createingSubstring(int begin,int sizeOdsubstring,char* string)
{
	char* temp = new char[sizeOdsubstring + 1];
	int k = 0;
	for (int i = begin; i < begin + sizeOdsubstring; i++)
		temp[k++] = string[i];
	temp[k] = '\0';
	return temp;
}

int indexing(char* substring,char* string)
{
	int sizeOfstring, sizeOfsubstring;
	sizeOfstring = lenght(string);
	sizeOfsubstring = lenght(substring);
	int LOC = 0;
	while (string[LOC] != substring[0] && LOC<sizeOfstring)
	{
		LOC++;
	}
	int k = 1;
	int counter = 1;
	for (int i = LOC+1; i < LOC + sizeOfsubstring;i++)
	if (string[i] == substring[k++])
		counter++;
	if (counter == sizeOfsubstring)
		return LOC;
	else
		return NULL;

}

char* concatenation(char* substring1, char* substring2)
{
	int size = lenght(substring1) + lenght(substring2);
	char* temp = new char[size + 1];
	for (int i = 0; i < lenght(substring1); i++)
		temp[i] = substring1[i];
	int j = lenght(substring1);
	for (int p = 0; p < lenght(substring2); p++)
		temp[j++] = substring2[p];
	temp[j] = '\0';
	return temp;
}

char* insert(int begin,char* substring,char* string)
{
	char* temp1 = createingSubstring(0,begin,string);
	char* temp2 = createingSubstring(begin + 1, lenght(string), string);
	char* temp3 = concatenation(temp1, substring);
	char* united = concatenation(temp3, temp2);
	return united;
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
}

char* replace(char* string, char* substring, char* replacement)
{
	int k = indexing(substring, string);
	char* temp1 = createingSubstring(0, k - 1, string);
	int size = lenght(substring);
	char* temp2 = createingSubstring(k + size, lenght(string) - size - k, string);
	char* temp3 = concatenation(temp1, replacement);
	char* UNITED = concatenation(temp3, temp2);
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	return UNITED;
	
}

char* deleteSubstring(int begin,int sizeOfsubstring,char* string)
{
	char* temp1 = createingSubstring(0, begin, string);
	char* temp2 = createingSubstring(begin+1, begin + sizeOfsubstring, string);
	char* temp3 = createingSubstring(begin + sizeOfsubstring + 1, lenght(string) - sizeOfsubstring - begin - 1, string);
	char* united = concatenation(temp1, temp3);
	string = united;
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	return united;
}

char* deleteEveryOther(char* string,char* substring)
{
	int br = 0;
	int i = 0;
	char* niz;
	int size = lenght(substring);
	int t = indexing(substring, string);
	if (t == NULL)
		return NULL;
	niz = createingSubstring(0, t + size, string);
	string=deleteSubstring(0, t + size, string);
	br++;
	while (string[i] != '\0')
	{
		t = indexing(substring, string);
		if (t != NULL)
			br++;
		else
			return concatenation(niz,string);
		if (br % 2 == 0)
		{
			i = t + size;
			string=deleteSubstring(t, size, string);
		}
		else
		{
			char* pom = createingSubstring(0, t + size, string);
			niz = concatenation(niz, pom);
			string=deleteSubstring(0, t + size, string);
			i = i + 1;
		}
	}
	return niz;
}

char* deleteAll(char* string, char* substring)
{
	char* p;
	int i = indexing(substring, string);
	while (i != NULL)
	{
		char* t1 = createingSubstring(0, i - 1, string);
		char* t2 = createingSubstring(i + 1 + lenght(substring), lenght(string) - i - lenght(substring), string);
		string = concatenation(t1, t2);
		i = indexing(substring,string);
	}
	p = string;
	return p;
}


void main()
{
	/*char* ptr1;
	char* ptr2;
	char b[] = "Ana voli Milovana";
	char c[] = "voli";
	ptr1 = b;
	ptr2 = c;
	int k = indexing(ptr2, ptr1);
	cout << ptr1 << endl;
	cout << ptr2 << endl;
	cout << "Pozicija od koje pocinje vas podstring je " << k << endl;
	char* united = concatenation(ptr1, ptr2);
	cout << "Konkatenacija vasih stringova daje sledeci string:   " << united << endl;
	char* sub = createingSubstring(3, 4, ptr1);
	cout << "Substring je:   " << sub << endl;



	char* ptr3;
	char d[] = "JOK";
	ptr3 = d;
	char* UNITED1 = insert(3, ptr3, ptr1);
	cout << "Nakon umetanja vas string je:  " << UNITED1 << endl;

	char* ptr4;
	char e[] = "JOK";
	ptr4 = e;
	char* UNITED2 = replace(ptr1, ptr2, ptr3);
	cout << "Nakon zamene vas string je:  " << UNITED2 << endl;
	char* deleted = deleteSubstring(3, 4, ptr1);
	cout << "Nakon brisanja sa pozicije 3 4 karaktera vas string je:  " << deleted << endl;

	*/


	char test[] = "Ana  voli   Miloana voli   Jocu  voli   Miku voli   Lazu  voli   Dacu voli Micu";
	cout << test;
	char proba[] = "voli";
	char *test1, *proba1;
	test1 = test;
	proba1 = proba;
	char* bla;
	bla=deleteAll(test1, proba1);
	cout << endl;
	cout << bla;
	cout << endl;
}