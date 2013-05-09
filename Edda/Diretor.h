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

#ifndef DIRETOR_H
#define DIRETOR_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include <stack>
#include <list>
#include <string>
using namespace std;

#include "Cena.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace Edda{

class DLLMAIN_API Atualizavel{
public:
	virtual void atualizar(long) = 0;
};

class DLLMAIN_API Diretor{
private:
	RenderWindow *win;
	stack<Cena*> cenas;
	Diretor();
	static Diretor *_instancia;
	list<Atualizavel*> atualizaveis;

	void atualizarAtualizaveis(long);

public:
	int larguraTela;
	int alturaTela;

	void iniciar(int,int,int,string,bool fullscreen=false);
	void adicionarCena(Cena *c);
	void loop(Cena *c);
	void adicionarAtualizavel(Atualizavel *);
	void limparAtualizaveis();

	static Diretor *getInstancia();
};
}
#endif