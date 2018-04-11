#include "Caracteristica.h"

Caracteristica::Caracteristica(int id, int custo_monetario, int custo_forca, int  defesa, int ataque, int saude, bool procura_ser, bool procura_edifico, bool ataca_edificio, bool ataca_ser) {
		this->id = id;
		this->custo_monetario = custo_monetario;
		this->custo_forca = custo_forca;

		this->defesa = defesa;
		this->ataque = ataque;
		this->saude = saude;

		this->procura_ser = procura_ser;
		this->procura_edificio = procura_edifico;
		this->ataca_edificio = ataca_edificio;
		this->ataca_ser = ataca_ser;
}
int Caracteristica::getCaracteristica() const { return id; }
int Caracteristica::get_custo_m() const { return custo_monetario; }
int Caracteristica::get_custo_f() const { return custo_forca; }
int Caracteristica::get_defesa() const { return defesa; }
int Caracteristica::get_ataque() const { return ataque; }
int Caracteristica::get_saude() const { return saude; }
bool Caracteristica::get_procura_ser() const { return procura_ser; }
bool Caracteristica::get_procura_edificio() const { return procura_edificio; }
bool Caracteristica::get_ataca_ser() const { return ataca_ser; }
bool Caracteristica::get_ataca_edificio() const { return ataca_edificio; }
string Caracteristica::toString() { ostringstream o; o << "[id = " << id << ",  custo_m = " << custo_monetario << ", custo_f = " << custo_forca << "]  "; return o.str(); }

Bandeira::Bandeira() : Caracteristica(1, 1, 0, 0, 0, 0, false, false, false, false) {}
Superior::Superior() : Caracteristica(2, 1, 1, 0, 0, 1, false, false, false, false) {}
Pele_Dura::Pele_Dura() : Caracteristica(3, 2, 2, 1, 0, 0, false, false, false, false) {}
Armadura::Armadura() : Caracteristica(4, 2, 3, 2, 0, 0, false, false, false, false) {}
Faca::Faca() : Caracteristica(5, 1, 1, 0, 1, 0, false, false, false, false) {}
Espada::Espada() : Caracteristica(6, 2, 2, 0, 2, 0, false, false, false, false) {}
Agressao::Agressao() : Caracteristica(7, 1, 1, 0, 0, 0, false, false, false, true) {}
Ecologico::Ecologico() : Caracteristica(8, 1, 1, 0, 0, 0, false, false, true, false) {}
HeatSeaker::HeatSeaker() : Caracteristica(9, 1, 1, 0, 0, 0, true, false, false, false) {}
BuildSeaker::BuildSeaker() : Caracteristica(10, 1, 1, 0, 0, 0, false, true, false, false) {}
Walker::Walker() : Caracteristica(11, 1, 1, 0, 0, 0, false, false, false, false) {}
Remedio::Remedio() : Caracteristica(12, 2, 1, 0, 0, 2, false, false, false, false) {}
SecondChance::SecondChance() : Caracteristica(13, 3, 0, 0, 0, 10, false, false, false, false) {}