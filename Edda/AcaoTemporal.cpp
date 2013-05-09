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

#include "AcaoTemporal.h"
#include <iostream>
namespace Edda{
AcaoTemporal::AcaoTemporal(): Acao() {
	duracao = 0;
	ultimoTempo = 0;
	tempoInicial = 0;
}

AcaoTemporal::AcaoTemporal(long d): Acao() {
	duracao = d;
	ultimoTempo = 0;
	tempoInicial = 0;
}

void AcaoTemporal::atualizar(long t){
//	cout << "t "<< t << " " << ultimoTempo << endl;
	if(duracao == 0){
		this->parar();
	}
	else{
		if(ultimoTempo==0){
			ultimoTempo=t;
			tempoInicial=t;
			this->passo(0);
		}
		else{
			long dt = t-tempoInicial;			
			if(dt>duracao){
				this->parar();
			}
			else{				
				this->passo(t-ultimoTempo);
				ultimoTempo=t;
			}
		}
	}
}
}