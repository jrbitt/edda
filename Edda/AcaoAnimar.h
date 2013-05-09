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

#ifndef ACAO_ANIMAR_H
#define ACAO_ANIMAR_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include "AcaoTemporal.h"
#include "Animacao.h"

namespace Edda{

class DLLMAIN_API AcaoAnimar: public AcaoTemporal{
private:
	Animacao *animacao;
	int ponteiro;
	long total;

public:
	AcaoAnimar(Animacao *);
	void passo(long);
	void executar(Nodo *);
};
}
#endif