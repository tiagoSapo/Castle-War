#pragma once
#include "Caracteristica.h"
#include "Header.h"

class Perfil {
	char letra;
	int MIN = 1, MAX = 13;
	vector <Caracteristica> v;
public:
	Perfil(int letra);
	bool adiciona_caracteristica(int caract);
	bool remove_caracteristica(int caract);
	int quantas_caract_tem();
	char get_letra();
	vector <Caracteristica>* get_vector_de_caract();
	string toString();
};
