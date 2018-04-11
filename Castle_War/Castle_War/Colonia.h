#pragma once
#include "Header.h"
#include "Edificio.h"
#include "Ser.h"
#include "Matriz.h"

class Colonia {

	char letra;
	int moedas;
	int cast_l, cast_c; // posicoes do castelo inicial
	vector<Edificio *> edificios;
	vector<Ser*> seres;

	bool verifica_coordenadas(int linhas, int colunas);
	bool get_coordenadas_castelo(int *l, int *c);

public:
	Colonia(char letra);
	void set_coordenadas_castelo_inicial(int l, int c);
	bool coord_ja_definidas();
	bool set_moedas(int m);
	void set_letra(char l);
	char get_letra();
	int get_linha();
	int get_coluna();
	int get_moedas();
	bool apaga_edificio(Matriz *planicie, int eid, bool permite_apagar_castelo);
	bool adiciona_edificio(Matriz *planicie, string tipo, int linha, int  coluna);
	bool reparar_edificio(Matriz *planicie, int eid);
	bool adiciona_ser(Matriz *planicie, Perfil *p, int n, int *seres_criados);
	bool ataca(Matriz *planicie);
	string toString();
};