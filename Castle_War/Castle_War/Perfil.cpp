#include "Perfil.h"

Perfil::Perfil(int letra) : letra(letra) {}
bool Perfil::adiciona_caracteristica(int caract) {
		if (caract >= MIN && caract <= MAX) {

			// Verifica se há caracteristicas iguais
			for (auto it = v.begin(); it != v.end(); it++) {
				if (it->getCaracteristica() == caract)
					return false;
			}
			if (caract == 1)
				v.push_back(Bandeira());
			else if (caract == 2)
				v.push_back(Superior());
			else if (caract == 3)
				v.push_back(Pele_Dura());
			else if (caract == 4)
				v.push_back(Armadura());
			else if (caract == 5)
				v.push_back(Faca());
			else if (caract == 6)
				v.push_back(Espada());
			else if (caract == 7)
				v.push_back(Agressao());
			else if (caract == 8)
				v.push_back(Ecologico());
			else if (caract == 9)
				v.push_back(HeatSeaker());
			else if (caract == 10)
				v.push_back(BuildSeaker());
			else if (caract == 11)
				v.push_back(Walker());
			else if (caract == 12)
				v.push_back(Remedio());
			else if (caract == 13)
				v.push_back(SecondChance());
			else
				return false;

			return true;
		}
		else
			return false;
	}
bool Perfil::remove_caracteristica(int caract) {
		for (auto it = v.begin(); it != v.end(); it++) {
			if (it->getCaracteristica() == caract) {
				v.erase(it);
				return true;
			}
		}
		return false;
	}
int Perfil::quantas_caract_tem() { return (int)v.size(); }
char Perfil::get_letra() { return letra; }
vector <Caracteristica>* Perfil::get_vector_de_caract() { return &v; }
string Perfil::toString() {

		ostringstream o;

		o << "Perfil [" << letra << "]:\n";
		for (auto it = v.begin(); it != v.end(); it++)
			o << it->toString() << endl;

		return o.str();
	}