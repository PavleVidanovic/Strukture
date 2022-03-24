#include "Node.h"
#include "SparseMatrix.h"

void main()
{
	SparseMatrix matrica(3,3);

	matrica.setAt(2, 0, 2);
	matrica.setAt(2, 1, 1);
	matrica.setAt(7, 1, 2);
	matrica.setAt(1, 2, 0);
	matrica.setAt(5, 2, 2);

	matrica.printAll();

	cout << "Element na poziciji 2,2 je: " << matrica.getAt(2, 2) << endl;
}