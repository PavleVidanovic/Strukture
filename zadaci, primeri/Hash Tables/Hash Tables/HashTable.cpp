#pragma once
#include "HashTable.h"

HashTable::HashTable()
{
	hashArray = NULL;
	current = 0;
	size = 0;
}

HashTable::~HashTable()
{
	delete[] hashArray;
}

HashTable::HashTable(int s)
{ 
	size = s;
	hashArray = new KeyWords*[s]; 
	current = 0;
	for (int i = 0; i < size; i++)
		hashArray[i] = NULL;
}

int HashTable::f(char* s)
{
	int result = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		result = result + s[i];
		i++;
	}
	result = result%size;
	return result;
};

void HashTable::insert(KeyWords* k)
{
	if (current == size - 1)
		throw "Tablica je puna";
	int index = f(k->key);
	current++;
	if (hashArray[index] != NULL)
	{
		if (hashArray[index]->next == NULL)
		{
			hashArray[index]->next = k;
			k->next = NULL;
		}
		else
		{
			KeyWords* tmp = hashArray[index]->next;
			KeyWords* prev = NULL;
			while (tmp != NULL)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			prev->next = k;
			k->next = NULL;
		}
	}
	else
		hashArray[index] = k;
};

KeyWords HashTable::find(char* c)
{
	int index = f(c);
	return *hashArray[index];
};

void HashTable::printAll()  
{
	for (int i = 0; i < size; i++)
	{
		if (hashArray[i] != NULL)
		{
			if (hashArray[i]->next != NULL)
			{
				hashArray[i]->print();
				KeyWords* tmp = hashArray[i]->next;
				while (tmp != NULL)
				{
					tmp->print();
					tmp = tmp->next;
				}
				cout << endl;
			}
			else
			{
				hashArray[i]->print();
			}
		}
		
	}
};

