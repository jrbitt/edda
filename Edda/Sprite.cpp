#include "Sprite.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Collision.h"

namespace Edda{
Sprite::Sprite(): Nodo(){
	rect = new vector<sf::IntRect*>;
	//current = img->begin();
	pos =0;
}

void Sprite::carregarImagem(string filename){	
	imageSource.LoadFromFile(filename);			
	_sprite.SetImage(imageSource);
	//current = img->begin();
}

void Sprite::carregarImagem(string filename,int larg,int alt){
	if(imageSource.LoadFromFile(filename)){
		_sprite.SetImage(imageSource);
		for(int y=0; y<imageSource.GetHeight(); y+=alt){
			for(int x=0; x<imageSource.GetWidth(); x+=larg){	
				IntRect *ir = new IntRect(x,y,larg,alt);							
				rect->push_back(ir);
			}
		}		
	}
}

void Sprite::desenhar(sf::RenderWindow *w){
	//w->Draw(*(*current));
	//w->Draw(*this->_sprite);
	//cout << "pintar "<< this << endl;	
	//_sprite->SetImage(NULL);
	this->_sprite.SetPosition(this->posicao.x,this->posicao.y);
	w->Draw(_sprite);
}

void Sprite::setPosicao(int x,int y){
	Nodo::setPosicao(x,y);	
	this->_sprite.SetPosition(x,y);
}

void Sprite::setFrame(int i){
	pos = i;
	std::cout << "set_frame " << (rect->at(pos)) << std::endl;
	_sprite.SetSubRect(*(rect->at(pos)));
}

/*sf::Image* Sprite::getFrame(int i){
	if(i>=0 && i<img->size()){
		return &(img->at(i));
	}
	else{
		return NULL;
	}
}*/

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
