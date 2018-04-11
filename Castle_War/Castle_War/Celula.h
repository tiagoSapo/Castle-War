#pragma once
#include "Header.h"
#include "Edificio.h"
#include "Ser.h"

class Celula {
	int x, y;
	Edificio *e;
	vector<Ser*> seres;
public:
	Celula();
	void set_coord(int x0, int y0);
	int tem_quantos_edificios();
	int tem_quantos_seres();
	bool adiciona_edificio(Edificio *edf);
	bool adiciona_ser(Ser *s);
	bool remove_edificio(Edificio *edf);
	bool remove_ser(Ser *s);
	string toString();
};
