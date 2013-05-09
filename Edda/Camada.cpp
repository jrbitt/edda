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

#include "Camada.h"

namespace Edda{
Camada::Camada(): Nodo(){
	
}

Camada::Camada(int r,int g,int b,int a): Nodo(){
	cor.r = r;
	cor.g = g;
	cor.b = b;
	cor.a = a;
}

void Camada::desenhar(RenderWindow *w){
	//if(square==NULL){ 
		square = sf::Shape::Rectangle(
			sf::Vector2f(posicao.x,posicao.y),
			sf::Vector2f(posicao.x+largura,posicao.y+altura),
			sf::Color(cor.r,cor.g,cor.b));
	//}
	w->Draw(square);
	if(!nodos.empty()){
		list<Nodo*>::iterator i;
		for(i=nodos.begin(); i!=nodos.end(); i++){
			(*i)->desenhar(w);
		}
	}
}

void Camada::adicionar(Nodo *n){
	Nodo::adicionar(n);
	nodos.push_back(n);
}

void Camada::remover(Nodo *n){
	Nodo::remover(n);
	nodos.remove(n);
	nodos.sort();
}
}