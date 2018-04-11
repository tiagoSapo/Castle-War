#include "Castle.h"

Castle::Castle() {
	planicie = nullptr;
	perfis = new vector<Perfil>;
	colonias = nullptr;
	jogador = new Colonia('a');
	moedas_iniciais = -1;
}
void Castle::start() {

	bool primeira_vez = true;
	bool fase_1 = false;
	bool fase_2 = false;
	
	string comando;
	string pal[5];

	while (1) {

		if (fase_1 == true && fase_2 == true)
			break;

		if (primeira_vez) {
			cout << "----------------- CASTLE WAR ------------------" << endl;
			primeira_vez = false;
		}
		cout << "\n> ";
		getline(cin, comando);
		istringstream cin_esp(comando);

		for (int i = 0; i < 5; i++)
			cin_esp >> pal[i];

		if (fase_1 == false && fase_2 == false)
			fase_1 = f1(pal);
		else if (fase_1 == true && fase_2 == false)
			fase_2 = f2(pal);

		for (int i = 0; i < 5; i++)
			pal[i].clear();
	}
}

bool Castle::f1(string *pal) {

	if (pal[0] == "dim")
		f1_dim(atoi(pal[1].c_str()), atoi(pal[2].c_str()));
	else if (pal[0] == "moedas")
		f1_moedas(atoi(pal[1].c_str()));
	else if (pal[0] == "oponentes")
		f1_oponentes(atoi(pal[1].c_str()));
	else if (pal[0] == "castelo")
		f1_castelo(pal[1].c_str()[0], atoi(pal[2].c_str()), atoi(pal[3].c_str()));
	else if (pal[0] == "mkperfil")
		f1_mkperfil(pal[1].c_str()[0]);
	else if (pal[0] == "addperfil")
		f1_addperfil(pal[1].c_str()[0], atoi(pal[2].c_str()));
	else if (pal[0] == "subperfil")
		f1_subperfil(pal[1].c_str()[0], atoi(pal[2].c_str()));
	else if (pal[0] == "rmperfil")
		f1_rmperfil(pal[1].c_str()[0]);
	else if (pal[0] == "load")
		f1_load(pal[1]);
	else if (pal[0] == "inicio")
		return f1_inicio();
	else
		cout << "ERRO: O comando '" << pal[0] << "' nao existe!\n";

	return false;
}
void Castle::f1_dim(int linhas, int colunas) {

	int MAX = 100;
	int MIN = 50;

	// verifica coordenadas
	if ((linhas >= MIN && linhas <= MAX) && (colunas >= MIN && colunas <= MAX)) {

		// se ainda não foi criada uma planicie
		if (planicie != nullptr) {
			if (colonias != nullptr) {
				colonias = new vector<Colonia>;
				delete colonias;
				colonias = nullptr;
			}
			if (jogador->coord_ja_definidas() == true)
				jogador->set_coordenadas_castelo_inicial(-1, -1);

			delete planicie;
		}

		// alocar nova matriz
		planicie = new Matriz(linhas, colunas);

		cout << "Foi criada uma planicie[" << linhas << "][" << colunas << "]\n";
	}
	else
		cout << "ERRO: Parametros invalido, nao e' possivel criar uma  planicie[" << linhas << "][" << colunas << "]\n";
}
void Castle::f1_moedas(int moedas) {

	int MAX = 10000;
	int MIN = 500;

	if (moedas >= MIN && moedas <= MAX) {
		moedas_iniciais = moedas;
		cout << "As moedas iniciais de todas as colonias passou a ser: " << moedas << "moedas!\n";
	}
	else
		cout << "ERRO: O valor '" << moedas << "' nao e' valido!\n";
}
void Castle::f1_oponentes(int oponentes) {

	int MAX = 5;
	int MIN = 1;

	if ((oponentes >= MIN && oponentes <= 5) && planicie != nullptr) {

		// limpa colonias anteriores
		if (colonias == nullptr)
			colonias = new vector<Colonia>;
		else
			colonias->clear();

		// cria n colonias
		char letra_inicial = 'b';
		for (int i = 0; i < oponentes; i++)
			colonias->push_back(Colonia(letra_inicial + i));

		for (auto it = colonias->begin(); it != colonias->end(); it++)
			cout << it->toString() << endl;

		cout << "Foram criados " << oponentes << " oponentes!\n";
	}
	else {
		if (planicie == nullptr)
			cout << "Tem que criar uma planicie primeiro!\n";
		else
			cout << "Valor invalido!\n";
	}
}
void Castle::f1_castelo(char colonia, int linha, int coluna) {

	if (planicie != nullptr) {

		if ((linha >= 0 && linha < planicie->get_linhas()) && (coluna >= 0 && coluna < planicie->get_colunas())) {

			if (colonia == 'a') {
				jogador->set_coordenadas_castelo_inicial(linha, coluna);
				cout << "O castelo inicial da minha colonia '" << colonia << "'  foi definido na posicao[" << linha << "][" << coluna << "]";
				return;
			}
			else {
				if (colonias != nullptr) {
					for (auto it = colonias->begin(); it != colonias->end(); it++)
						if (it->get_letra() == colonia) {
							it->set_coordenadas_castelo_inicial(linha, coluna);
							cout << "O castelo inicial da colonia '" << colonia << "' foi  definido na posicao[" << linha << "][" << coluna << "]";
							return;
						}
					cout << "ERRO: A colonia '" << colonia << "' nao existe!\n";
					return;
				}
				else {
					cout << "ERRO: Nao foi ainda definido o numero de oponentes!\n";
					return;
				}

			}
		}
		else
			cout << "ERRO: Esta posicao nao e' valida!\n";
	}
	else
		cout << "ERRO: Ainda nao foi definida uma planicie!\n";
}
void Castle::f1_mkperfil(char letra) {

	if (letra >= 'a' && letra <= 'z') {
		// Verifica se este perfil já existe
		for (auto it = perfis->begin(); it != perfis->end(); it++)
			if (it->get_letra() == letra) {
				cout << "ERRO: O perfil '" << it->get_letra() << "' ja existe!\n";
				return;
			}

		perfis->push_back(Perfil(letra));
		cout << "Foi adicionado um novo perfil '" << letra << "'\n";
	}

	else
		cout << "ERRO: O valor '" << letra << "' nao e' uma letra valida!\n";
}
void Castle::f1_addperfil(char letra, int id) {
	if (letra >= 'a' && letra <= 'z') {
		// Verifica se este perfil já existe
		for (auto it = perfis->begin(); it != perfis->end(); it++)
			if (it->get_letra() == letra) {
				if (it->adiciona_caracteristica(id) == true)
					cout << "A caracteristica '" << id << "' foi adicionada ao  perfil'" << it->get_letra() << "' com SUCESSO!\n";
				else
					cout << "ERRO: A caracteristica'" << id << "' nao e' uma  caracteristica valida, ou ja' existe neste perfil!\n";
				return;
			}
		cout << "ERRO: O perfil '" << letra << "' nao existe!\n";
	}

	else
		cout << "ERRO: O valor '" << letra << "' nao e' uma letra valida!\n";
}
void Castle::f1_subperfil(char letra, int id) {

	if (letra >= 'a' && letra <= 'z') {

		// Verifica se este perfil já existe
		for (auto it = perfis->begin(); it != perfis->end(); it++)
			if (it->get_letra() == letra) {
				if (it->remove_caracteristica(id) == true)
					cout << "A caracteristica '" << id << "' foi removida ao perfil'" << it->get_letra() << "' com SUCESSO!\n";
				else
					cout << "ERRO: A caracteristica '" << id << "' nao existe neste  perfil!\n";
				return;
			}
		cout << "ERRO: O perfil '" << letra << "' nao existe!\n";
	}

	else
		cout << "ERRO: O valor '" << letra << "' nao e' uma letra valida!\n";
}
void Castle::f1_rmperfil(char letra) {

	if (letra >= 'a' && letra <= 'z') {

		for (auto it = perfis->begin(); it != perfis->end(); it++)
			if (it->get_letra() == letra) {
				perfis->erase(it);
				cout << "O perfil '" << letra << "' foi apagado com sucesso!\n";
				return;
			}

		cout << "ERRO: O perfil '" << letra << "' nao existe!\n";
	}

	else
		cout << "ERRO: O valor '" << letra << "' nao e' uma letra valida!\n";
}
bool Castle::f1_inicio() {

	if (planicie == nullptr) {
		cout << "ERRO: A planicie ainda nao foi definida!\n";
		return false;
	}

	if (perfis->size() == 0) {
		cout << "ERRO: Nao existem ainda perfis definidos!\n";
		return false;
	}

	bool tem_caracteristicas = false;
	for (auto it = perfis->begin(); it != perfis->end(); it++) {
		if (it->quantas_caract_tem() > 0)
			tem_caracteristicas = true;
	}
	if (tem_caracteristicas == false) {
		cout << "ERRO: Nao existe, pelo menos, um perfil com uma caracteristica!\n";
		return false;
	}

	if (colonias == nullptr) {
		cout << "ERRO: Ainda nao foi definido o numero de oponentes!\n";
		return false;
	}

	if (moedas_iniciais == -1) {
		cout << "ERRO: Ainda nao foi definido o numero de moedas iniciais  das colonias!\n";
		return false;
	}

	//cout << planicie->mostra() << endl;
	do {

		// adiciona coordenadas e moedas ao jogador se ainda estiverem a -1
		jogador->set_moedas(moedas_iniciais);
		if (jogador->coord_ja_definidas() == false)
			jogador->set_coordenadas_castelo_inicial(rand() % planicie->get_linhas(), rand() % planicie->get_colunas());

		// adiciona coordenadas e moedas aos oponentes se ainda estiverem a -1
		for (auto it = colonias->begin(); it != colonias->end(); it++) {
			it->set_moedas(moedas_iniciais);
			if (it->coord_ja_definidas() == false)
				it->set_coordenadas_castelo_inicial(rand() % planicie->get_linhas(), rand() % planicie->get_colunas());
		}

		bool ja_existe = false;
		for (auto it = colonias->begin(); it != colonias->end(); it++) {
			int l = it->get_linha();
			int c = it->get_coluna();
			char letra = it->get_letra();
			for (auto it2 = colonias->begin(); it2 != colonias->end(); it2++) {
				if ((l == it2->get_linha() && c == it2->get_coluna()) && (it2->get_letra() != letra)) {
					it->set_coordenadas_castelo_inicial(rand() % planicie->get_linhas(), rand() % planicie->get_colunas());
					ja_existe = true;
					break;
				}
				if (ja_existe == true)
					break;
			}
			if (ja_existe == false)
				break;

		}

		int l = jogador->get_linha();
		int c = jogador->get_coluna();

		for (auto it = colonias->begin(); it != colonias->end(); it++) {
			if ((l == it->get_linha() && c == it->get_coluna())) {
				jogador->set_coordenadas_castelo_inicial(rand() % planicie->get_linhas(), rand() % planicie->get_colunas());
				ja_existe = true;
				break;
			}
		}

		if (ja_existe == false)
			break;

	} while (1);

	jogador->adiciona_edificio(planicie, "castelo", jogador->get_linha(), jogador->get_coluna());

	cout << "OK: A iniciar simulacao...\n";
	return true;
}
void Castle::f1_load(string txt) {

	string frase, pal[5];
	ifstream f(txt.c_str());

	if (f.is_open()) {
		while (getline(f, frase)) {
			istringstream cin_esp(frase);
			for (int i = 0; i < 5; i++)
				cin_esp >> pal[i];
			if (pal[0] != "load" && pal[0] != "inicio")
				f1(pal);
			for (int i = 0; i < 5; i++)
				pal[i].clear();
		}
		f.close();
	}

}

bool Castle::f2(string *pal) {

	if (pal[0] == "foco") {
		cout << planicie->mostra();
	}
	else if (pal[0] == "zoomout") {}
	else if (pal[0] == "setmoedas")
		f2_set_moedas(pal[1].c_str()[0], atoi(pal[2].c_str()));
	else if (pal[0] == "build")
		f2_build(pal[1], atoi(pal[2].c_str()), atoi(pal[3].c_str()));
	else if (pal[0] == "list")
		f2_list(pal[1].c_str()[0]);
	else if (pal[0] == "listp")
		f2_listp(pal[1].c_str()[0]);
	else if (pal[0] == "listallp")
		f2_listallp();
	else if (pal[0] == "mkbuild")
		f2_mkbuild(pal[1], atoi(pal[2].c_str()), atoi(pal[3].c_str()), pal[4].c_str()[0]);
	else if (pal[0] == "repair")
		f2_repair(atoi(pal[1].c_str()));
	else if (pal[0] == "upgrade") {}
	else if (pal[0] == "sell")
		f2_sell(atoi(pal[1].c_str()));
	else if (pal[0] == "ser")
		f2_ser(atoi(pal[1].c_str()), pal[2].c_str()[0]);
	else if (pal[0] == "next") {}
	else if (pal[0] == "nextn") {}
	else if (pal[0] == "ataca")
		f2_ataca();
	else if (pal[0] == "recolhe") {}
	else if (pal[0] == "fim") { return true; }
	else if (pal[0] == "restore") {}
	else if (pal[0] == "erase") {}
	else if (pal[0] == "load") {}
	else
		cout << "O comando '" << pal[0] << "' nao existe.\n";

	return false;
}
void Castle::f2_set_moedas(char colonia, int m) {

	if (colonia == 'a') {
		if (jogador->set_moedas(m) == true)
			cout << "O valor em moedas da colonia 'a' passou a " << m << " moedas!\n";
		else
			cout << "ERRO: O valor de moedas nao e' valido." << endl;
		return;
	}
	else {
		for (auto it = colonias->begin(); it != colonias->end(); it++)
			if (it->get_letra() == colonia) {
				if (it->set_moedas(m) == true)
					cout << "O valor em moedas da colonia '" << colonia << "' passou  a " << m << " moedas!\n";
				else
					cout << "ERRO: O valor de moedas nao e' valido." << endl;
				return;
			}

		cout << "ERRO: A colonia nao existe!\n";
	}

}
void Castle::f2_list(char colonia) {

	if (colonia == 'a')
		cout << jogador->toString() << endl;
	else {

		if (colonia > 'a' && colonia <= 'z') {
			for (auto it = colonias->begin(); it != colonias->end(); it++)
				if (it->get_letra() == colonia) {
					cout << it->toString() << endl;
					return;
				}
			cout << "ERRO: A colonia '" << colonia << "' nao existe.\n";
		}
		else
			cout << "ERRO: '" << colonia << "' nao e' um nome valido.\n";

	}

}
void Castle::f2_listp(char perfil) {

	for (auto it = perfis->begin(); it != perfis->end(); it++)
		if (it->get_letra() == perfil) {
			cout << it->toString();
			return;
		}

}
void Castle::f2_listallp() {
	for (auto it = perfis->begin(); it != perfis->end(); it++)
		cout << it->toString();
}
void Castle::f2_build(string tipo, int linha, int coluna) {

	if (jogador->adiciona_edificio(planicie, tipo, linha, coluna) == true)
		cout << "Foi criado um novo edificio do tipo '" << tipo << "' na  posicao[" << linha << "][" << coluna << "]!\nOBS: Saldo actual = " << jogador->get_moedas() << endl;
	else
		cout << "ERRO: Nao possivel criar o edificio por falta de moedas ou  a posicao nao e' valida!\n";
}
void Castle::f2_mkbuild(string tipo, int linha, int coluna, char colonia) {

	if (colonia == 'a') {
		if (jogador->adiciona_edificio(planicie, tipo, linha, coluna) == true)
			cout << "Foi criado um novo edificio do tipo '" << tipo << "' na  posicao[" << linha << "][" << coluna << "]!\nOBS: Saldo actual = " << jogador->get_moedas() << endl;
		else
			cout << "ERRO: Nao possivel criar o edificio por falta de moedas ou  a posicao nao e' valida!\n";
		return;
	}

	for (auto it = colonias->begin(); it != colonias->end(); it++) {
		if (it->get_letra() == colonia) {
			if (it->adiciona_edificio(planicie, tipo, linha, coluna) == true)
				cout << "Foi criado um novo edificio do tipo '" << tipo << "' na  posicao[" << linha << "][" << coluna << "]!\nOBS: Saldo actual = " << it->get_moedas() << endl;
			else
				cout << "ERRO: Nao possivel criar o edificio por falta de moedas  ou a posicao nao e' valida!\n";
			return;
		}
	}

	cout << "ERRO: A colonia '" << colonia << "' nao existe!\n";
}
void Castle::f2_sell(int eid) {

	if (jogador->apaga_edificio(planicie, eid, false) == true)
		cout << "O edificio '" << eid << "' foi apagado com sucesso!\nOBS:  Saldo actual = " << jogador->get_moedas() << " moedas.\n";
	else
		cout << "ERRO: O edificio nao existe, nao me pretence, ou estara' a  tentar apagar o seu castelo!\n";

}
void Castle::f2_repair(int eid) {

	if (jogador->reparar_edificio(planicie, eid) == true)
		cout << "O edificio '" << eid << "' foi reparado com sucesso.\n";
	else
		cout << "O edificio nao existe, nao me pretence, ou nao existem  moedas suficientes para o reparar.\n";

}
void Castle::f2_ser(int n, char perfil) {

	int seres_criados = 0;

	for (auto it = perfis->begin(); it != perfis->end(); it++) {
		if (it->get_letra() == perfil) {
			if (jogador->adiciona_ser(planicie, &(*it), n, &seres_criados) == true) {
				if (seres_criados != n) {
					cout << "Foram criados '" << seres_criados << "' com a  caracteristica '" << perfil << "'.\n";
				}
				else
					cout << "Foram criados '" << seres_criados << "' com a  caracteristica '" << perfil << "'.\n";
			}
			else
				cout << "ERRO: Parametros invalidos ou nao existe moedas suficientes.\n";
		}

	}

}
void Castle::f2_ataca() {

	jogador->ataca(planicie);
	cout << planicie->mostra() << endl;

}
