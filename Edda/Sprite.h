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

#ifndef SPRITE_H
#define SPRITE_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include "Nodo.h"
#include <string>
#include <vector>
#include "SFML\Graphics.hpp"

using namespace std;

namespace Edda{
class DLLMAIN_API Sprite: public Nodo{
private:
	vector<sf::IntRect*> *rect;
	sf::Sprite _sprite;
	sf::Image imageSource;
	int pos;

public:
	Sprite();

	void carregarImagem(string);
	void carregarImagem(string,int,int);
	void desenhar(sf::RenderWindow *);
	void setPosicao(int,int);
	void setFrame(int);
	bool colidir(Sprite *s, bool pixel=true);
	
	//Vazio deve ser sobrescrito
	void tratarEvento(RenderWindow *){}
};
}
#endif