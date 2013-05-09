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
\brief namespace único da solução
*/
namespace Edda{

class Nodo;

//!Classe que descreve uma ação
/*!
Uma ação modifica o estado de um nodo no tempo
*/
class DLLMAIN_API Acao{
protected:
	Nodo *alvo;						/*!< nodo alvo da ação */
	bool rodando;					/*!< se ação está executando */

public:
	int tag;						/*!< id identifcador da ação */

	//! Construtor padrão da ação.
	/*!
	Cria uma nova ação com tag 0, sem executar e com alvo nulo.
	*/
	Acao();
	
	//!Verifica se ação está pronta.
	/*!
	Verifica se a ação está pronta
	\return true caso a ação conclui sua execução
	*/
	bool estaPronta();	

	//!Para uma ação.
	/*!
	Para de executar uma ação
	*/
	void parar();

	//!Executa uma ação.
	/*!
	Método virtual para executar uma determinada ação.
	Guarda um nodo e troca o estado da ação para executando.
	\param considera como alvo um nodo
	*/
	virtual void executar(Nodo *);

	//!Um passo da ação durante a execução da simulação.
	/*!
	Método virtual padrão que não faz nada.
	\param o delta tempo entre uma atualização e outra
	*/
	virtual void passo(long dt);
	
	//!Método virtual puro de atualização
	/*!
	As ações devem sobrescrever este método. Trata-se
	da lógica da atualização que deverá ser feita por
	uma ação.
	\param o delta tempo entre uma atualização e outra
	*/
	virtual void atualizar(long)=0;
};
}
#endif