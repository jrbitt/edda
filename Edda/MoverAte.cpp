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

#include "MoverAte.h"
#include <iostream>
namespace Edda{
MoverAte::MoverAte(int x, int y, long d){
	tx = x;
	ty = y;
	ax = 0.0f;
	ay = 0.0f;
	duracao = d;
}

void MoverAte::passo(long t){
	cout << this->alvo->getX() << " " << this->alvo->getY() << endl;
	ax += dx;
	ay += dy;
	this->alvo->setPosicao(ax,ay);	
}

void MoverAte::executar(Nodo *n){ 
	this->Acao::executar(n);
	dx = (tx - this->alvo->getX())/(float)duracao;
	dy = (ty - this->alvo->getY())/(float)duracao;	
	ax = this->alvo->getX();
	ay = this->alvo->getY();
}
}