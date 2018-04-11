#pragma once
#include "Header.h"

class Edificio {
	char letra;
	static int id;
	int eid, custo, saude, defesa, saude_inicial;
	int pos_l, pos_c;
public:
	Edificio(int custo, int saude, int defesa, int l, int c, char letra);
	int get_saude();
	int get_custo();
	int get_eid();
	int get_saude_inicial();
	int get_id();
	int get_l();
	int get_c();
	void set_saude(int s);
	void set_coordenadas(int l, int c);
	char get_letra();
};

class Castelo : public Edificio {
public:
	Castelo(int l, int c, char letra);
};
class Torre : public Edificio {
public:
	Torre(int l, int c, char letra);
};
class Quinta : public Edificio {
public:
	Quinta(int l, int c, char letra);
};