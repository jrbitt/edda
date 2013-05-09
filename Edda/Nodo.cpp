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

#include "Nodo.h"
#include <iostream>

namespace Edda{
Nodo::Nodo(){
	dadosUsuario = NULL;
	tag = -1;
	largura = 0;
	altura = 0;
	zorder = 0;
	posicao.x =0; posicao.y =0;
	ancora.x=0; ancora.y=0;
	visivel = true;
	filhos = new map<int,Nodo*>;
	ptrAcoes = acoes.begin();
}

void Nodo::adicionar(Nodo *n){
	filhos->insert(map<int, Nodo*>::value_type(n->tag,n));
	n->pai = this;
}

void Nodo::remover(Nodo *n){
	map<int,Nodo*>::iterator i = filhos->find(n->tag);
	if(i!=filhos->end()){
		filhos->erase(i);
	}
}

Nodo *Nodo::pegarNodoPelaTag(int tag){
	map<int,Nodo*>::iterator i = filhos->find(tag);
	if(i!=filhos->end()){
		return i->second;
	}
	else{
		return NULL;
	}
}

void Nodo::adicionarAcao(Acao *a){
	acoes.push_back(a);
}

void Nodo::pararAcao(Acao *a){
	for(ptrAcoes;ptrAcoes!=acoes.end(); ptrAcoes++){
		if(*ptrAcoes == a){
			ptrAcoes = acoes.erase(ptrAcoes);
		}
	}
	if(!acoes.empty()){
		ptrAcoes = acoes.begin();
	}
	else{
		rodando = false;
	}
}

void Nodo::pararTodasAsAcoes(){
	for(ptrAcoes;ptrAcoes!=acoes.end(); ptrAcoes++){
		(*ptrAcoes)->parar();
	}
	if(!acoes.empty()){
		ptrAcoes = acoes.begin();
	}
	acoes.clear();
	rodando = false;
}

bool Nodo::estaRodando(){
	return rodando;
}

void Nodo::executar(){
	ptrAcoes = acoes.begin();
	for(ptrAcoes;ptrAcoes!=acoes.end(); ptrAcoes++){		
		(*ptrAcoes)->executar(this);
	}

	map<int,Nodo*>::iterator i;
	for(i=filhos->begin(); i!=filhos->end();i++){
		i->second->executar();
	}
}

void Nodo::passo(long dt){
	for(ptrAcoes;ptrAcoes!=acoes.end(); ptrAcoes++){
		(*ptrAcoes)->passo(dt);
	}
	ptrAcoes = acoes.begin();
}

void Nodo::atualizar(long t){			
	ptrAcoes = acoes.begin();
	for(ptrAcoes;ptrAcoes!=acoes.end(); ptrAcoes++){
		if((*ptrAcoes)->estaPronta()){
			(*ptrAcoes)->atualizar(t);
		}	
		else{
			ptrAcoes = acoes.erase(ptrAcoes);
		}
	}
	
	map<int,Nodo*>::iterator i;
	for(i=filhos->begin(); i!=filhos->end();i++){
		i->second->atualizar(t);
	}
}

void Nodo::setPosicao(int x,int y){
	posicao.x = x;
	posicao.y = y;
}

int Nodo::getX(){
	return posicao.x;
}

int Nodo::getY(){
	return posicao.y;
}
}