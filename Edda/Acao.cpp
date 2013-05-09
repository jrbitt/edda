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

#include "Acao.h"
#include <iostream>

namespace Edda{

Acao::Acao(){
	alvo = NULL;
	rodando = false;
	tag = 0;
}

void Acao::executar(Nodo *n){
	alvo = n;
	rodando = true;
}

bool Acao::estaPronta(){
	return rodando;
}

void Acao::passo(long){
}

void Acao::parar(){
	//alvo = NULL;
	rodando = false;
	std::cout << "para " << std::endl;
}
}