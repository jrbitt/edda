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
#ifndef ACAO_H
#define ACAO_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include "Nodo.h"

/*!
\namespace Edda 
\brief namespace �nico da solu��o
*/
namespace Edda{

class Nodo;

//!Classe que descreve uma a��o
/*!
Uma a��o modifica o estado de um nodo no tempo
*/
class DLLMAIN_API Acao{
protected:
	Nodo *alvo;						/*!< nodo alvo da a��o */
	bool rodando;					/*!< se a��o est� executando */

public:
	int tag;						/*!< id identifcador da a��o */

	//! Construtor padr�o da a��o.
	/*!
	Cria uma nova a��o com tag 0, sem executar e com alvo nulo.
	*/
	Acao();
	
	//!Verifica se a��o est� pronta.
	/*!
	Verifica se a a��o est� pronta
	\return true caso a a��o conclui sua execu��o
	*/
	bool estaPronta();	

	//!Para uma a��o.
	/*!
	Para de executar uma a��o
	*/
	void parar();

	//!Executa uma a��o.
	/*!
	M�todo virtual para executar uma determinada a��o.
	Guarda um nodo e troca o estado da a��o para executando.
	\param considera como alvo um nodo
	*/
	virtual void executar(Nodo *);

	//!Um passo da a��o durante a execu��o da simula��o.
	/*!
	M�todo virtual padr�o que n�o faz nada.
	\param o delta tempo entre uma atualiza��o e outra
	*/
	virtual void passo(long dt);
	
	//!M�todo virtual puro de atualiza��o
	/*!
	As a��es devem sobrescrever este m�todo. Trata-se
	da l�gica da atualiza��o que dever� ser feita por
	uma a��o.
	\param o delta tempo entre uma atualiza��o e outra
	*/
	virtual void atualizar(long)=0;
};
}
#endif