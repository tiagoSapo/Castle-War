#include "Matriz.h"

bool Matriz::verifica_coordenadas(int l, int c) {
		if ((l >= 0 && l < linhas) && (c >= 0 && c < colunas))
			return true;
		else
			return false;
	}
bool Matriz::esta_disponivel_edificio(int linha, int coluna) {
		if (verifica_coordenadas(linha, coluna) == false)
			return false;
		if (p[linha][coluna].tem_quantos_edificios() == 0)
			return true;
		else
			return false;
	}
bool Matriz::esta_disponivel_ser(int linha, int coluna) {
		if (verifica_coordenadas(linha, coluna) == false)
			return false;
		if ((p[linha][coluna].tem_quantos_edificios() == 0 && p[linha][coluna].tem_quantos_seres() == 0) || (p[linha][coluna].tem_quantos_edificios() == 1))
			return true;
		else
			return false;
	}
Matriz::Matriz(int linhas, int colunas) : linhas(linhas), colunas(colunas) {

		p = new Celula*[linhas];
		for (int i = 0; i < linhas; ++i)
			p[i] = new Celula[colunas];

		for (int i = 0; i < linhas; i++)
			for (int j = 0; j < colunas; j++)
				p[i][j].set_coord(i, j);
	}
int Matriz::get_linhas() { return linhas; }
int Matriz::get_colunas() { return colunas; }
bool Matriz::coloca_edificio(Edificio *e, int linha, int coluna) {
		if (this->esta_disponivel_edificio(linha, coluna) == false)
			return false;
		if (p[linha][coluna].adiciona_edificio(e) == false)
			return false;
		else
			return true;
	}
bool Matriz::remove_edificio(Edificio *e) {
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				if (p[i][j].remove_edificio(e) == true) {
					return true;
				}
			}
		}
		return false;
	}
bool Matriz::coloca_ser(Ser *s, int linha, int coluna) {
		if (this->esta_disponivel_ser(linha, coluna) == false)
			return false;
		if (p[linha][coluna].adiciona_ser(s) == false)
			return false;
		else
			return true;
	}
bool Matriz::remove_ser(Ser *s, int linha, int coluna) {

		if (p[linha][coluna].remove_ser(s) == true)
			return true;
		else
			return false;

	}
string Matriz::mostra() {
		ostringstream o;
		for (int i = 0; i < linhas; i++) {
			o << i << "\t| ";
			for (int j = 0; j < colunas; j++) {
				o << p[i][j].toString() << " ";
			}
			o << endl;
		}

		return o.str();
	}