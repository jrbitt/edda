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

#include "Cena.h"

namespace Edda{
Cena::Cena(): Nodo(){
}
void Cena::desenhar(RenderWindow *w){
	map<int,Nodo*>::iterator i;
	if(!filhos->empty()){
		for(i=filhos->begin(); i!=filhos->end(); i++){
			i->second->desenhar(w);
		}
	}
}

void Cena::tratarEvento(RenderWindow *win){
	Event ev;
	while (win->GetEvent(ev)){
		// Window closed
		if (ev.Type == Event::Closed){
			win->Close();
		}
		// Escape key pressed
		else if ((ev.Type == Event::KeyPressed) && (ev.Key.Code == Key::Escape)){
			win->Close();
		}
		else{
			map<int,Nodo *>::iterator it = filhos->begin();
			for(it; it!=filhos->end(); it++){
				it->second->tratarEvento(win);
			}
		}
	}
}
}