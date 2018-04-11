#include "Colonia.h"
bool Colonia::verifica_coordenadas(int linhas, int colunas) {
		if ((cast_l >= 0 && cast_l < linhas) && (cast_c >= 0 && cast_c < colunas))
			return true;
		else
			return false;
}
bool Colonia::get_coordenadas_castelo(int *l, int *c) {

		*l = -1;
		*c = -1;

		for (auto it = edificios.begin(); it != edificios.end(); it++) {
			if ((*it)->get_custo() == 0) {
				*l = (*it)->get_l();
				*c = (*it)->get_c();
				return true;
			}
		}
		return false;
	}
Colonia::Colonia(char letra) : letra(letra), moedas(-1), cast_l(-1), cast_c(-1) {}
void Colonia::set_coordenadas_castelo_inicial(int l, int c) { cast_l = l;  cast_c = c; }
bool Colonia::coord_ja_definidas() { if (cast_l == -1 || cast_c == -1)return  false; else return true; }
bool Colonia::set_moedas(int m) { if (m < 0)return false; moedas = m; return true; }
void Colonia::set_letra(char l) { letra = l; }
char Colonia::get_letra() { return letra; }
int Colonia::get_linha() { return cast_l; }
int Colonia::get_coluna() { return cast_c; }
int Colonia::get_moedas() { return moedas; }
bool Colonia::apaga_edificio(Matriz *planicie, int eid, bool permite_apagar_castelo) {

		if (permite_apagar_castelo == false) {
			for (auto it = edificios.begin(); it != edificios.end(); it++) {
				if ((*it)->get_eid() == eid && (*it)->get_custo() != 0) {  /*  get_custo != 0 -> nao permite apagar castelo */
					if (planicie->remove_edificio(*it) == true) {
						moedas += ((*it)->get_custo() / 2);
						delete (*it);
						edificios.erase(it);
						return true;
					}
					break;
				}
			}
			return false;
		}
		else {
			for (auto it = edificios.begin(); it != edificios.end(); it++) {
				if ((*it)->get_eid() == eid) {
					if (planicie->remove_edificio(*it) == true) {
						moedas += ((*it)->get_custo() / 2);
						delete (*it);
						edificios.erase(it);
						return true;
					}
					break;
				}
			}
			return false;
		}
	}
bool Colonia::adiciona_edificio(Matriz *planicie, string tipo, int linha, int  coluna) {

		Edificio *e = nullptr;
		if (tipo == "castelo")
			e = new Castelo(linha, coluna, letra);
		else if (tipo == "torre")
			e = new Torre(linha, coluna, letra);
		else if (tipo == "quinta")
			e = new Quinta(linha, coluna, letra);
		else
			return false;

		if (moedas - e->get_custo() < 0) {
			delete e;
			return false;
		}

		if (planicie->coloca_edificio(e, linha, coluna) == true) {
			moedas -= e->get_custo();
			edificios.push_back(e);
			return true;
		}

		delete e;
		return false;
	}
bool Colonia::reparar_edificio(Matriz *planicie, int eid) {

		for (auto it = edificios.begin(); it != edificios.end(); it++) {
			if ((*it)->get_eid() == eid) {
				if (((*it)->get_saude() * (1 - ((*it)->get_saude() / (*it)->get_saude_inicial()))) < 0)
					return false;
				moedas -= ((*it)->get_saude() * (1 - ((*it)->get_saude() / (*it)->get_saude_inicial())));
				(*it)->set_saude((*it)->get_saude_inicial());
				return true;
			}
		}

		return false;
	}
bool Colonia::adiciona_ser(Matriz *planicie, Perfil *p, int n, int *seres_criados) {

		*seres_criados = 0;
		int l = -1, c = -1;

		// procura coordenadas do castelo
		for (auto it = edificios.begin(); it != edificios.end(); it++) {
			if ((*it)->get_custo() == 0) {
				l = (*it)->get_l();
				c = (*it)->get_c();
				break;
			}
		}

		if (l == -1 || c == -1)
			return false;


		for (int i = 0; i < n; i++) {
			Ser *s = new Ser(*p, letra);

			if (moedas - s->get_custo_monetario() < 0)
				delete s;

			if (s->ser_valido() == false)
				delete s;

			if (planicie->coloca_ser(s, l, c) == true) {
				moedas -= s->get_custo_monetario();
				seres.push_back(s);
				(*seres_criados)++;
			}
			else
				delete s;
		}

		if (*seres_criados == 0)
			return false;
		else
			return true;

	}
bool Colonia::ataca(Matriz *planicie) {

		int l;
		int c;

		if (get_coordenadas_castelo(&l, &c) == false)
			return false;

		vector<Ser*> copia;
		for (auto it = seres.begin(); it != seres.end(); it++)
			copia.push_back(*it);

		for (auto it = seres.begin(); it != seres.end(); it++) {
			if (planicie->coloca_ser(*it, l - 1, c - 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l - 1, c) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l - 1, c + 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l, c - 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l, c + 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l + 1, c - 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l + 1, c) == true) {
				planicie->remove_ser(*it, l, c);
			}
			else if (planicie->coloca_ser(*it, l + 1, c + 1) == true) {
				planicie->remove_ser(*it, l, c);
			}
		}

		return true;
	}
string Colonia::toString() {

		ostringstream o;

		o << "Colonia " << letra << ": moedas = " << moedas << ", seres = " << "SERES" << ", edificios = " << (int)edificios.size() << "[EID = ";
		for (auto it = edificios.begin(); it != edificios.end(); it++)
			o << (*it)->get_id() << " ";
		o << "]";

		return o.str();
	}