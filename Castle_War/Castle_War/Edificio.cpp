#include "Edificio.h"

Edificio::Edificio(int custo, int saude, int defesa, int l, int c, char letra) { eid = ++id; this->saude_inicial = saude, this->custo = custo;  this->defesa = defesa; this->saude = saude; this->pos_l = l;  this->pos_c = c; this->letra = letra; }
int Edificio::get_saude() { return saude; }
int Edificio::get_custo() { return custo; }
int Edificio::get_eid() { return eid; }
int Edificio::get_saude_inicial() { return saude_inicial; }
int Edificio::get_id() { return eid; }
int Edificio::get_l() { return pos_l; }
int Edificio::get_c() { return pos_c; }
void Edificio::set_saude(int s) { saude = s; }
void Edificio::set_coordenadas(int l, int c) { pos_l = l; pos_c = c; }
char Edificio::get_letra() { return letra; }

int Edificio::id = 0;

Castelo::Castelo(int l, int c, char letra) : Edificio(0, 50, 10, l, c, letra) {}
Torre::Torre(int l, int c, char letra) : Edificio(30, 20, 10, l, c, letra) {}
Quinta::Quinta(int l, int c, char letra) : Edificio(20, 20, 10, l, c, letra) {}