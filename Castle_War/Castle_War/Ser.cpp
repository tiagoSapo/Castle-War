#include "Ser.h"

Ser::Ser(Perfil p, char colonia) : saude(10), forca(10), bandeira(0) {

		procura_ser = false;
		procura_edificio = false;
		ataca_edficio = false;
		ataca_ser = false;

		ataque = 0;
		defesa = 0;
		custo_forca = 0;
		custo_monetario = 0;

		for (auto it = p.get_vector_de_caract()->begin(); it != p.get_vector_de_caract()->end(); it++) {
			if (it->getCaracteristica() == 1)
				bandeira = colonia;
			if (it->get_procura_ser() == true)
				procura_ser = true;
			if (it->get_procura_edificio() == true)
				procura_edificio = true;
			if (it->get_ataca_edificio() == true)
				ataca_edficio = true;
			if (it->get_ataca_ser() == true)
				ataca_ser = true;
			if (it->get_saude() > 0)
				saude += it->get_saude();
			if (it->get_ataque() > 0)
				ataque += it->get_ataque();
			if (it->get_defesa() > 0)
				defesa += it->get_defesa();

			custo_forca += it->get_custo_f();
			custo_monetario += it->get_custo_m();
		}

		forca -= custo_forca;
	}
int Ser::get_custo_forca() { return custo_forca; }
bool Ser::ser_valido() { if (forca < 0)return false; else return true; }
int Ser::get_custo_monetario() { return custo_monetario; }
char Ser::get_bandeira() { if (bandeira == 0) return '?'; else  return bandeira; }
string Ser::toString() {

		ostringstream o;

		o << "BANDEIRA = " << bandeira << endl;
		o << "Saude = " << saude << endl;
		o << "Forca = " << forca << endl;
		o << "Ataque = " << ataque << endl;
		o << "Defesa = " << defesa << endl;
		o << "Procura_Ser = " << procura_ser << endl;
		o << "Procura_Edificio = " << procura_edificio << endl;
		o << "Ataque_edificio = " << ataca_edficio << endl;
		o << "Ataque_ser = " << ataca_ser << endl;

		return o.str();
	}
