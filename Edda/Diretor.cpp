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

#include "Diretor.h"
#include "SFML\System.hpp"
#include "SFML\Config.hpp"

using namespace sf; 

namespace Edda{

Diretor* Diretor::_instancia = NULL;

Diretor::Diretor(){
}

Diretor* Diretor::getInstancia(){
	if(_instancia==NULL){
		_instancia = new Diretor;
	}
	return _instancia;
}

void Diretor::iniciar(int larg, int alt, int bpp,string titulo,bool fullscreen){
	win = new RenderWindow(VideoMode(larg,alt,bpp),titulo,(fullscreen)?Style::Fullscreen:Style::Titlebar);
	larguraTela = larg;
	alturaTela = alt;
}

void Diretor::adicionarCena(Cena *c){
	if(!cenas.empty()){
		cenas.top()->pararTodasAsAcoes();
	}
	cenas.push(c);
	c->executar();
}

void Diretor::loop(Cena *c){
	adicionarCena(c);
	Clock timer;
	timer.Reset();
	float delta,start = 0;
	while (win->IsOpened()){
		start = timer.GetElapsedTime()*1000;
		//Eventos de I/O
		cenas.top()->tratarEvento(win);

		this->atualizarAtualizaveis(start);

		//Processa a logica
		cenas.top()->atualizar(start);

		//Render

		win->Clear();
		if(!cenas.empty()){			
			cenas.top()->desenhar(win);
		}
		win->Display();
	}
}

void Diretor::adicionarAtualizavel(Atualizavel *a){
	this->atualizaveis.push_back(a);
}

void Diretor::limparAtualizaveis(){
	this->atualizaveis.clear();
}

void Diretor::atualizarAtualizaveis(long t){
	if(!atualizaveis.empty()){
		list<Atualizavel*>::iterator it = atualizaveis.begin();
		for(it; it!=atualizaveis.end(); it++){
			(*it)->atualizar(t);
		}
	}
}

}
