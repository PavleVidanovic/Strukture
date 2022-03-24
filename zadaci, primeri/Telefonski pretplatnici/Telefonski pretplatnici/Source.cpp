#pragma onde
#include "Grad.h"
#include "Pretplatnici.h"

void main()
{
	Grad Nis(100);
	Pretplatnici p1(9347010, "Danica");
	Pretplatnici p2(3592684, "Gaga");
	Pretplatnici p3(2950965, "Radica");
	Pretplatnici p4(3225867, "Slavisa");
	Nis.insert(&p1);
	Nis.insert(&p2);
	Nis.insert(&p3);
	Nis.insert(&p4);
	Nis.printAll();
}