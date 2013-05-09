#include "Tilemap.h"
#include <iostream>

namespace Edda{
TileCache* TileCache::inst = 0;

void TileCache::desenhar(RenderWindow * win, int index,int x, int y)
{
	
	if(index < 0) return;
	if(index >= vetor.size()) return;

	vetor[index]->SetPosition(x,y);
	win->Draw(*(vetor[index]));
}

int TileCache::carregar(string arquivo)
{
	//int pos = localizar(arquivo);
	//if(pos >= 0) return pos;

	Image *temp = new Image;
	bool ret;

	ret = temp->LoadFromFile(arquivo);
	
	if(ret)
	{
		vetorImg.push_back(*temp);
		vetor.push_back(new Sprite(*temp));
		mapa.push_back(arquivo);
		return vetor.size()-1;
	}
	else
	{
		delete temp;
		return -1;
	}
}

int  TileCache::carregar(string arquivo, int px, int py, int largura, int altura)
{
	Image temp;
	Image temp2;
	temp2.Create(largura,altura);
	bool ret;

	
	ret = temp.LoadFromFile(arquivo);
	temp2.Copy(temp,0,0,IntRect(px,py,largura,altura),true);

	if(ret)
	{
		vetorImg.push_back(temp);
		vetor.push_back(new Sprite(temp2));
		mapa.push_back(arquivo);
		return vetor.size()-1;
	}
	else
	{
		return -1;
	}
}


int TileCache::localizar(string arquivo)
{
	int sz = mapa.size();
	for(int i=0;i<sz;i++)
		if(mapa[i] == arquivo) return i;		
	
	return -1;
}

Sprite* TileCache::getImagem(int index)
{
	if(index < 0) return 0;
	if(index >= vetor.size()) return 0;

	return vetor[index];
}

int TileCache::getNumTiles()
{
	return vetor.size();
}

TileCache* TileCache::instance()
{
	if(!inst)
	{
		inst = new TileCache();
		return inst;
	}
	else return inst;
}
void TileCache::destruir()
{
	if(inst)
	{
		delete inst;
		inst = 0;
	}
}

TileCache::TileCache()
{
	// SINGLETON - construtor static
}

TileCache::~TileCache()
{
	for(int i = 0; i < vetor.size(); i++)
		delete vetor[i];
}
}