#pragma once
#include "Header.h"
#include "Matriz.h"
#include "Perfil.h"
#include "Colonia.h"

class Castle {

	Matriz *planicie;
	vector<Perfil> *perfis;
	vector<Colonia> *colonias;
	Colonia *jogador;
	int moedas_iniciais;

	bool f1(string *);
	void f1_dim(int, int);
	void f1_moedas(int);
	void f1_oponentes(int);
	void f1_castelo(char, int, int);
	void f1_mkperfil(char);
	void f1_addperfil(char, int);
	void f1_subperfil(char, int);
	void f1_rmperfil(char);
	bool f1_inicio();
	void f1_load(string);

	bool f2(string *);
	void f2_set_moedas(char, int);
	void f2_list(char);
	void f2_listp(char);
	void f2_listallp();
	void f2_build(string, int, int);
	void f2_mkbuild(string, int, int, char);
	void f2_sell(int);
	void f2_repair(int);
	void f2_ser(int, char);
	void f2_ataca();

public:
	Castle();
	void start();
};