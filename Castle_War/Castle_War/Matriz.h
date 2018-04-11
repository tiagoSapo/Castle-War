#pragma once
#include "Header.h"
#include "Celula.h"

class Matriz {
	Celula **p;
	int linhas, colunas;

	bool verifica_coordenadas(int l, int c);
	bool esta_disponivel_edificio(int linha, int coluna);
	bool esta_disponivel_ser(int linha, int coluna);
public:
	Matriz(int linhas, int colunas);
	int get_linhas();
	int get_colunas();
	bool coloca_edificio(Edificio *e, int linha, int coluna);
	bool remove_edificio(Edificio *e);
	bool coloca_ser(Ser *s, int linha, int coluna);
	bool remove_ser(Ser *s, int linha, int coluna);
	string mostra();
};



