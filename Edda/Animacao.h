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

#ifndef ANIMACAO_H
#define ANIMACAO_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include <vector>
#include "SFML\Graphics.hpp"
#include "Sprite.h"

using namespace std;
namespace Edda{
class DLLMAIN_API Frame{
public:
	Frame(int i,long d=1){
		indexFrame = i;
		unidadesDelay = d;
	}
	int indexFrame; 
	long unidadesDelay;
};

class DLLMAIN_API Animacao{
public:		
	int loops;
	vector<Frame*> frames;
	Sprite *sprite;

	long getDuracao();
	int getTotalUnidades();
	long getDelay(int);

	void adicionarFrame(Frame *);
	void adicionarFrames(int *,int);
	void adicionarFrames(int *,int *,int);
	void adicionarFrames(int,int);
};
}
#endif