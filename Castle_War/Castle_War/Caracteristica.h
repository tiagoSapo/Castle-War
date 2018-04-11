#pragma once
#include "Header.h"
class Caracteristica {
	int id;
	int custo_monetario;
	int custo_forca;

	int defesa;
	int ataque;
	int saude;

	bool procura_ser, procura_edificio, ataca_edificio, ataca_ser;
public:
	Caracteristica(int id, int custo_monetario, int custo_forca, int  defesa, int ataque, int saude, bool procura_ser, bool procura_edifico, bool ataca_edificio, bool ataca_ser);
	int getCaracteristica() const;
	int get_custo_m() const;
	int get_custo_f() const;
	int get_defesa() const;
	int get_ataque() const;
	int get_saude() const;
	bool get_procura_ser() const;
	bool get_procura_edificio() const;
	bool get_ataca_ser() const;
	bool get_ataca_edificio() const;
	string toString();
};
class Bandeira : public Caracteristica {
public:
	Bandeira();
};
class Superior : public Caracteristica {
public:
	Superior();
};
class Pele_Dura : public Caracteristica {
public:
	Pele_Dura();
};
class Armadura : public Caracteristica {
public:
	Armadura();
};
class Faca : public Caracteristica {
public:
	Faca();
};
class Espada : public Caracteristica {
public:
	Espada();
};
class Agressao : public Caracteristica {
public:
	Agressao();
};
class Ecologico : public Caracteristica {
public:
	Ecologico();
};
class HeatSeaker : public Caracteristica {
public:
	HeatSeaker();
};
class BuildSeaker : public Caracteristica {
public:
	BuildSeaker();
};
class Walker : public Caracteristica {
public:
	Walker();
};
class Remedio : public Caracteristica {
public:
	Remedio();
};
class SecondChance : public Caracteristica {
public:
	SecondChance();
};
