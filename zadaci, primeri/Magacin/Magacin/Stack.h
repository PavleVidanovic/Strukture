#pragma once
#include "iostream"
#include "string.h"
using namespace std;

class Stack
{
private:
	int* niz;
	int trenutno, size;
public:
	Stack(){ trenutno = -1; size = 0; niz = NULL; }
	Stack(int n){ trenutno = -1; size = n; niz = new int[size]; }
	~Stack(){ if (niz != NULL) delete[] niz; }
	void push(int a){ if (trenutno == size - 1) throw "Pun niz"; niz[++trenutno] = a; }
	int pop(){ if (trenutno == -1) return 0; else{ int b = niz[trenutno]; trenutno--; return b; } }
	int peek(){ if (trenutno >= 0) return niz[trenutno]; else return 0; }
	void print()
	{
		while (!isEmpty())
		{
			cout << peek() << ' '; 
			pop(); 
		} 
	}
	bool isEmpty(){ return trenutno == -1; }
	int addLong(char* a,char* b)
	{
		Stack s1(strlen(a));
		Stack s2(strlen(b));
		Stack s3(10);
		int i = 0;
		while (a[i] != '\0')
		{
			s1.push(a[i] - '0');
			i++;
		}
		i = 0;
		while (b[i] != '\0')
		{
			s2.push(b[i] - '0');
			i++;
		}
		while (!s1.isEmpty() || !s2.isEmpty())
		{
			int m = s1.pop() + s2.pop() +s3.pop();
			if (m > 10)
			{
				s3.push(1);
				push(m - 10);
			}
			else
				push(m);
		}
		if (s1.isEmpty())
		{
			while (!s2.isEmpty())
			{
				int m = s3.pop() + s2.pop();
				if (m > 10)
				{
					s3.push(1);
					push(m - 10);
				}
				else
					push(m);
			}
		}
		else if (s2.isEmpty())
		{
			while (!s1.isEmpty())
			{
				int m = s3.pop() + s1.pop();
				if (m > 10)
					s3.push(1);
				else
					push(m);
			}
		}
		int s = 0;
		while (!isEmpty())
		{
			s = s * 10;
			s = s + pop();
			
		}
		return s;
	}
};