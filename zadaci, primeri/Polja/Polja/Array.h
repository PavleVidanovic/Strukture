#pragma once
#include "iostream"
using namespace std;


template <class T>
class Array
{
public:
	Array();
	Array(int n);
	~Array();
	int arrayBinarySearch(int dg, int gg, T E);
	int arrayLinearSearch(int n, T E);
	void arrayTraversal(int d, int g);
	void bubbleSort();
	//void mergeSort();  !!!!!!!!!!!!!!!!!!!
	void store(int p, T E);
	T extract(int p);
	void output();
private:
	int size;
	T* array;
};

template <class T>
Array<T>::Array()
{
	size = 0;
	array = nullptr;
};

template <class T>
Array<T>::Array(int n)
{
	size = n;
	array = new T[size];
};

template <class T>
Array<T>::~Array()
{
	if (array != nullptr)
		delete[]array;
};

template <class T>
int Array<T>::arrayBinarySearch(int dg, int gg, T E)
{
	
	int front, back;
	back = gg;
	front = dg;
	int middle = (dg + gg) / 2;
	while (front < back && array[middle] != E)
	{
		if (E < array[middle])
			back = middle - 1;
		else
			front = middle + 1;
		middle = (front + back) / 2;
	}
	if (array[middle] == E)
		return middle;
	else
		return NULL;

};

template <class T>
int Array<T>::arrayLinearSearch(int n, T E)
{
	int LOC = 0;
	while (LOC < n && array[LOC] != E)
	{
		LOC++;
	}
	if (array[LOC] == E)
		return LOC;
	else
		return NULL;

};



template <class T>
void Array<T>::arrayTraversal(int d, int g)
{
	for (int i = d; i < g; i++)
		array[i]++;
};

template <class T>
void Array<T>::bubbleSort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		if (array[i]>array[j])
		{
			T temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
};

template <class T>
void Array<T>::store(int p, T E)
{
	if (p > size || p < 0)
		throw "Los indeks";
	array[p] = E;
};

template <class T>
T Array<T>::extract(int p)
{
	if (p > size || p < 0)
		throw "Los indeks";
	return array[p];
};

template <class T>
void Array<T>::output()
{
	for (int i = 0; i < size; i++)
		cout << i << " " << array[i] << endl;
};