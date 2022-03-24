#include "iostream"
#include "String.h"
using namespace std;


void trazenje(int* a, int* b, int n,int e)
{
	int i = 0;
	int j = 0;
	while (i < n)
	{
		if (a[i] == e)
			b[j++] = i;
		i++;
	}
}

void main()
{
	int a[] = { 1, 2, 3, 3, 2, 1, 3, 4, 5, 3, 1, 2, 3 };
	int n = 13;
	int* ptra = a;
	int b[10];
	int* ptrb=b;
	trazenje(ptra, ptrb, n, 3);
	for (int i = 0; i < 10; i++)
		if (b[i]!=NULL)
			cout << b[i] << " ";
}