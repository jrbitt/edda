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

#include "Sequencia.h"
#include <iostream>

namespace Edda{
Sequencia::Sequencia(): Colecoes(){
	
}

void Sequencia::atualizar(long t){
	if(pos<acoes.size()){
		if(acoes[pos]->estaPronta()){
			acoes[pos]->atualizar(t);
		}
		else{			
			pos++;
			if(pos<acoes.size()){
				acoes[pos]->executar(this->alvo);
				acoes[pos]->atualizar(t);
			}
		}
	}
	AcaoTemporal::atualizar(t);
}
}