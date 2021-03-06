#include "SparseMatrix.h"


SparseMatrix::SparseMatrix()
{
	row = 0;
	col = 0;
	rows = NULL;
	colums = NULL;
}


SparseMatrix::~SparseMatrix()
{
	for (int i = 0; i < row; i++)
		rows[i] = NULL;
	for (int j = 0; j < col; j++)
		colums[j] = NULL;
	delete[] rows;
	delete[] colums;
}

SparseMatrix::SparseMatrix(int i, int j) // i-broj vrsta , j-broj kolona
{
	row = i;
	rows = new Node*[i];
	colums = new Node*[j];
	col = j;
	for (int i = 0; i < row; i++)
		rows[i] = NULL;
	for (int j = 0; j < col; j++)
		colums[j] = NULL;
};


void SparseMatrix::setAt(int el, int r, int c)
{
	Node *temp = new Node();
	temp->column_postion = c;
	temp->row_position = r;
	temp->data = el;
	temp->nextRow = NULL;
	temp->nextColumn = NULL;
	if (rows[r] == NULL)  // rows[r] je kao head za datu kolonu
		rows[r] = temp;
	else if (rows[r]->nextRow == NULL)
	{
		if (rows[r]->column_postion < temp->column_postion)
			rows[r]->nextRow = temp;
		else
		{
			rows[r]->nextRow = temp;
			temp->nextRow = rows[r];
		}
	}
	else
	{
		Node *help = rows[r];
		while (help->nextRow != NULL && help->column_postion < c)
		{
			help = help->nextRow;
		}
		if (c == help->column_postion)
			help->data = el;
		else
		{
			if (help->nextRow == NULL)
				help->nextRow = temp;
			else
			{
				temp->nextRow = help->nextRow;
				help->nextRow = temp;
			}
		}
	}

	// za KOLONU

	if (colums[c] == NULL)  // rows[r] je kao head za datu kolonu
		colums[c] = temp;
	else if (colums[c]->nextColumn == NULL)
	{
		if (colums[c]->row_position < temp->row_position)
			colums[c]->nextColumn = temp;
		else
		{
			colums[c]->nextColumn = temp;
			temp->nextColumn = colums[c];
		}
	}
	else
	{
		Node *help = colums[c];
		while (help->nextColumn != NULL && help->row_position < r)
		{
			help = help->nextColumn;
		}
		if (r == help->row_position)  //azuriranje
			help->data = el;
		else
		{
			if (help->nextColumn == NULL)
				help->nextColumn = temp;
			else
			{
				temp->nextColumn = help->nextColumn;
				help->nextColumn = temp;
			}
		}
	}
		

		

};

int SparseMatrix::getAt(int i, int j) // i-vrsta , j-kolona
{
	Node* temp;
	for (temp = rows[i]; temp != NULL; temp = temp->nextRow)
	{
		if (temp->column_postion == j)
			return temp->data;
	}
	return 0;
};

void SparseMatrix::printAll()
{
	for (int i = 0; i < row; i++)
	{
		Node* tmp = rows[i];
		if (tmp == NULL)
		{
			for (int k = 0; k < col; k++)
				cout << "0 ";
		}

		else
		{
			Node* help = rows[i];
			Node* another;
			int p = 0;
			while (help!=NULL)
			{
				for (int z = p; z < help->column_postion; z++)
				{
						cout << "0 ";
						p = help->column_postion + 1;
					
				}
				cout << help->data<<" ";
				help = help->nextRow;
			}
			if (p < col)
			{
				for (int k = p; k < col;k++)
					cout << "0 ";
			}
		}

		cout << endl;
	}
};
