#pragma once
#include "Node.h"
#include "Stablo.h"


void main()
{
	Stablo* s = new Stablo();
	Stablo* s2 = new Stablo();
	s2->insert(13);
	s2->insert(12);
	s2->insert(30);
	s2->insert(45);
	s2->insert(51);
	s2->insert(2);
	s2->insert(1);


	s->insert(15);
	s->insert(10);
	s->insert(20);
	s->insert(8);
	s->insert(25);
	s->insert(17);
	s->insert(4);
	/*s->insertNoBTS(10, s->returnRoot());
	s->insertNoBTS(20, s->returnRoot());
	s->insertNoBTS(20, s->returnRoot());
	s->insertNoBTS(12, s->returnRoot());
	s->insertNoBTS(17, s->returnRoot());
	s->print(s->returnRoot());
	if (s->isBTS(s->returnRoot()))
		cout << "BTS je" << endl;
	else
		cout << "Nije BTS" << endl;
	
	

	s->print(s->returnRoot());
	cout << "Nalazenje maksimuma i minimuma iterativnim postupkom" << endl;
	cout << s->findMax();
	cout << endl;
	cout << s->findMin();
	cout << endl;
	cout << "Nalazenje maksimuma i minimuma koriscenjem rekurzije" << endl;
	cout << s->findMaxRec(s->returnRoot());
	cout << endl;
	cout << s->findMinRec(s->returnRoot());
	cout << endl;
	cout << "Visina stabla je " << s->findHight(s->returnRoot()) << endl;
	cout << "Broj razlicitih elemenata je " << s->brojRazlicitih() << endl;
	cout << "Broj elemenata u nizu je " << s->brojEl(s->returnRoot()) << endl;
	cout << "Tezina stabla je " << s->tezina(s->returnRoot()) << endl;
	//cout << "Brisanje" << endl;
	//s->deleteAll(s->returnRoot());
	//if (s->isEmpty())
	//	cout << "Prazna je" << endl;
	//else
	//	cout << "Nije obrisana" << endl;
	
	cout << "Trazenje elementa 10" << endl;
	Node* smesti = new Node(); //nece da smesti 10 u node smesti
	if (s->search(s->returnRoot(), 10, smesti))
	{
		cout << "Element je nadjen" << endl;
	}
	else
		cout << "Element nije nadjen" << endl;
	if (s->isBTS(s->returnRoot()))
		cout << "BTS je" << endl;
	else
		cout << "Nije BTS" << endl;

	int a[5] = { 1, 2, 3, 4, 5 };
	Stablo* drugo = s->sortedArrayToBTS(a, 5);  //radi
	drugo->print(drugo->returnRoot());*/

	cout << "Broj levih deteta prvog stabla je " << s->prebrojiLeve(s->returnRoot()) << endl;

	cout << "Broj levih deteta drugog stabla je " << s2->prebrojiLeve(s2->returnRoot()) << endl;

	
}