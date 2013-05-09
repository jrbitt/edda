/*
    Edda - A 2D game library
    Copyright (C) 2013  Jo�o Ricardo Bittencourt

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

#include "Colecoes.h"

namespace Edda{
Colecoes::Colecoes(){
	pos = 0;
}

void Colecoes::adicionar(AcaoTemporal *a){
	acoes.push_back(a);		
}

void Colecoes::executar(Nodo *n){ 
	this->Acao::executar(n);
	this->alvo = n;	
	for(int i=0; i<acoes.size(); i++){
		acoes[i]->executar(n);
		duracao += acoes[i]->getDuracao();
	}		
}

void Colecoes::passo(long t){	
}
}