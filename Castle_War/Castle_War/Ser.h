#pragma once
#include "Header.h"
#include "Perfil.h"

class Ser {
	char bandeira;
	int saude, forca, ataque, defesa, custo_forca, custo_monetario;
	bool procura_ser, procura_edificio, ataca_edficio, ataca_ser;
public:
	Ser(Perfil p, char colonia);
	int get_custo_forca();
	bool ser_valido();
	int get_custo_monetario();
	char get_bandeira();
	string toString();
};
