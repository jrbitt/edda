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

#include "Animacao.h"
namespace Edda{
long Animacao::getDuracao() {
	long t = 0;
	for(int i=0; i<frames.size(); i++){
		t += frames[i]->unidadesDelay;
	}
	return t;
}
int Animacao::getTotalUnidades(){
	return frames.size();
}

long Animacao::getDelay(int u){
	return frames[u]->unidadesDelay;
}

void Animacao::adicionarFrame(Frame *f){
	frames.push_back(f);
}

void Animacao::adicionarFrames(int inicio,int fim){
	for(int i=inicio; i<=fim; i++){
		adicionarFrame(new Frame(i,1000));
	}
}

void Animacao::adicionarFrames(int *idf,int totalFrames){
	for(int i=0; i<totalFrames; i++){
		adicionarFrame(new Frame(idf[i],1000));
	}
}

void Animacao::adicionarFrames(int *idf, int *tempos, int totalFrames){
	for(int i=0; i<totalFrames; i++){
		adicionarFrame(new Frame(idf[i],tempos[i]));
	}
}
}