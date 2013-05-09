#include "Sprite.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Collision.h"

namespace Edda{
Sprite::Sprite(): Nodo(){
	current = img.begin();
	pos =0;
}

void Sprite::carregarImagem(string filename){	
	sf::Image tmp;
	tmp.LoadFromFile(filename);
	if(img.empty()){				
		_sprite = new sf::Sprite(tmp);
	}				
	img.push_back(&tmp);
	current = img.begin();
}

void Sprite::carregarImagem(string filename,int larg,int alt){
	sf::Image tmp;
	if(tmp.LoadFromFile(filename)){
		for(int y=0; y<tmp.GetHeight(); y+=alt){
			for(int x=0; x<tmp.GetWidth(); x+=larg){
				Image *temp2 = new Image;
				temp2->Create(larg,alt);
				temp2->Copy(tmp,0,0,IntRect(x,y,larg,alt),false);

				if(img.empty()){				
					_sprite = new sf::Sprite(*temp2);
				}				
				img.push_back(temp2);
			}
		}					
		current = img.begin();
	}
}

void Sprite::desenhar(sf::RenderWindow *w){
	//w->Draw(*(*current));
	//w->Draw(*this->_sprite);
	//cout << "pintar "<< this << endl;	
	w->Draw(*this->_sprite);
}

void Sprite::setPosicao(int x,int y){
	Nodo::setPosicao(x,y);	
	this->_sprite->SetPosition(x,y);
}

void Sprite::setFrame(int i){
	//std::cout << "set_frame " << this << std::endl;
	pos = i;
	this->_sprite->SetImage(*(img[pos]));
}

sf::Image* Sprite::getFrame(int i){
	if(i>=0 && i<img.size()){
		return img[i];
	}
	else{
		return NULL;
	}
}

bool Sprite::colidir(Sprite *s, bool pixel){
	if(Collision::BoundingBoxTest(*(this->_sprite),*(s->_sprite))){
		if(pixel){
			return Collision::PixelPerfectTest(*(this->_sprite),*(s->_sprite));
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}
}
}
/*
CCAnimation *animation = 
[CCAnimation animationWithName:@"dance" delay:0.2f frames:animFrames];
		
[sprite runAction:[CCRepeatForever actionWithAction: [CCAnimate actionWithAnimation:animation restoreOriginalFrame:NO] ]];
*/
