#include "Celula.h"

Celula::Celula() : x(-1), y(-1), e(nullptr) {}
void Celula::set_coord(int x0, int y0) { x = x0; y = y0; }
int Celula::tem_quantos_edificios() { if (e == nullptr)return 0; else return 1; }
int Celula::tem_quantos_seres() { return (int)seres.size(); }
bool Celula::adiciona_edificio(Edificio *edf) {
		if (e == nullptr && edf != nullptr) {
			e = edf;
			return true;
		}
		else
			return false;
}
bool Celula::adiciona_ser(Ser *s) {
		if (s != nullptr) {
			if ((e == nullptr && seres.size() == 0) || (e != nullptr)) {
				seres.push_back(s);
				return true;
			}
			else
				return false;
		}
		else
			return false;
}
bool Celula::remove_edificio(Edificio *edf) {
		if (edf == e && edf != nullptr) {
			e = nullptr;
			return true;
		}
		else
			return false;
}
bool Celula::remove_ser(Ser *s) {

		if (s == nullptr)
			return false;

		for (auto it = seres.begin(); it != seres.end(); it++)
			if (s == *it) {
				seres.erase(it);
				return true;
			}
		return false;
}
string Celula::toString() {

		ostringstream o;

		if (e == nullptr && seres.size() == 0)
			o << ".";
		else if (e == nullptr && seres.size() == 1) {
			for (auto it = seres.begin(); it != seres.end(); it++) {
				o << (char)(*it)->get_bandeira();
				break;
			}
		}
		else if (e != nullptr && seres.size() == 0)
			o << (char)(e->get_letra() - 32);
		else if (e != nullptr && seres.size() > 0) {
			o << (char)(e->get_letra() - 32);
			o << "+";
		}
		else
			o << "?";
		return o.str();
}
