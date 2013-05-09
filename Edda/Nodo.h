/*
    Edda - A 2D game library
    Copyright (C) 2013  João Ricardo Bittencourt

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NODO_H
#define NODO_H

#include "SFML\Graphics.hpp"
#include "Ponto.h"
#include "Acao.h"

#include <map>
#include <list>
using namespace std;
using namespace sf;
#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

namespace Edda{
class Acao;

class DLLMAIN_API Nodo{
private:	
	bool rodando;
	list<Acao*> acoes;
	list<Acao*>::iterator ptrAcoes;

protected:
	map<int,Nodo *> *filhos;
	Ponto posicao;

public:
	void* dadosUsuario;
	int tag;
	int largura;
	int altura;
	int zorder;
	
	Ponto ancora;
	bool visivel;
	Nodo *pai;

	Nodo();
	virtual void desenhar(RenderWindow *) = 0;	
	virtual void tratarEvento(RenderWindow *) = 0;
	void adicionar(Nodo *n);
	void remover(Nodo *n);
	Nodo *pegarNodoPelaTag(int tag);
	
	void executar();
	void adicionarAcao(Acao *);
	void pararAcao(Acao *);
	void pararTodasAsAcoes();
	void passo(long dt);
	void atualizar(long);

	bool estaRodando();

	bool operator<=(Nodo *b){
		return this->zorder <= b->zorder;
	}

	virtual void setPosicao(int,int);
	int getX();
	int getY();
};
}
#endif