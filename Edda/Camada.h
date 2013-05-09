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

#ifndef CAMADA_H
#define CAMADA_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include "Nodo.h"
#include "Cor.h"

#include <list>
#include "SFML\Graphics.hpp"
using namespace std;

namespace Edda{
class DLLMAIN_API Camada: public Nodo{
private:	
	Cor cor;
	sf::Shape square;

protected:
	list<Nodo*> nodos;

public:
	Camada();
	Camada(int,int,int,int a=0);
	void desenhar(RenderWindow *);
	void adicionar(Nodo *n);
	void remover(Nodo *n);
	
	//Vazio deve ser sobrescrito
	void tratarEvento(RenderWindow *){}
};
}
#endif