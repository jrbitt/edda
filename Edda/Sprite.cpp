#include "Sprite.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Collision.h"

namespace Edda{
Sprite::Sprite(): Nodo(){
	rect = new vector<sf::IntRect*>;
	pos =0;
}

void Sprite::carregarImagem(string filename){	
	if(imageSource.LoadFromFile(filename)){
		imageSource.SetSmooth(false);
		_sprite.SetImage(imageSource);
	}
}

void Sprite::carregarImagem(string filename,int larg,int alt){
	if(imageSource.LoadFromFile(filename)){
		imageSource.SetSmooth(false);
		_sprite.SetImage(imageSource);
		for(int y=0; y<imageSource.GetHeight(); y+=alt){
			for(int x=0; x<imageSource.GetWidth(); x+=larg){	
				IntRect *ir = new IntRect(x,y,x+larg,y+alt);						
				rect->push_back(ir);
			}
		}		
	}
}

void Sprite::desenhar(sf::RenderWindow *w){
	this->_sprite.SetPosition(this->posicao.x,this->posicao.y);
	w->Draw(_sprite);	
}

void Sprite::setPosicao(int x,int y){
	Nodo::setPosicao(x,y);	
	this->_sprite.SetPosition(x,y);
}

void Sprite::setFrame(int i){
	pos = i;
	_sprite.SetSubRect(*(rect->at(pos)));
}

bool Sprite::colidir(Sprite *s, bool pixel){
	if(Collision::BoundingBoxTest((this->_sprite),(s->_sprite))){
		if(pixel){
			return Collision::PixelPerfectTest((this->_sprite),(s->_sprite));
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
