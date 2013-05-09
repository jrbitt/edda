#include "Tilemap.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace Edda{
Tilemap::Tilemap(void): Camada()
{

	posicao.x = posicao.y = 0;
}

Tilemap::~Tilemap(void)
{
}

bool Tilemap::inicializa(string arq)
{
	int delta;
	int tilesX, tilesY;
	int larg, alt;
	string tile_num;
	string nome_arq;
	tile_num = "*";

	ifstream arq_mapa(arq.c_str());
	if(!arq_mapa.is_open()) return false;

	arq_mapa >> tilesX >> tilesY;
	arq_mapa >> larg >> alt;

	delta = iSC->getNumTiles();	
	
	arq_mapa >> tile_num;
	while(arq_mapa >> nome_arq)
	{
		iSC->carregar(nome_arq);
		arq_mapa >> tile_num;
		if(tile_num == "*") break;
	}
	
	if( (tilesX < 1) || (tilesY < 1)) return false;

	mapa.resize(tilesX);
	for(int i = 0; i < tilesX; i++)
		mapa[i].resize(tilesY);

	tx = tilesX; ty = tilesY;
	lx = larg; ly = alt;

	largura = tx*lx;
	altura = ty*ly;
	
	
	int tile_atual;
	for(int y = 0; y < tilesY; y++)
	{
		for(int x = 0; x < tilesX; x++)
		{
			arq_mapa >> tile_atual;
			if(tile_atual >= 0) tile_atual += delta;
			mapa[x][y] = new Tile();
			mapa[x][y]->posx = x;
			mapa[x][y]->posy = y;			
			mapa[x][y]->setTile(tile_atual,larg,alt);
		}
	}
	
	string sep;
	arq_mapa >> sep;
	if(sep != "*") return false;

	int bw_atual;
	for(int y = 0; y < tilesY; y++)
	{
		for(int x = 0; x < tilesX; x++)
		{
			arq_mapa >> bw_atual;
			mapa[x][y]->setWalk((bool)bw_atual);
		}
	}

	arq_mapa >> sep;
	if(sep != "*") return false;
	
	for(int y = 0; y < tilesY; y++)
	{
		for(int x = 0; x < tilesX; x++)
		{
			arq_mapa >> bw_atual;
			mapa[x][y]->setInfo(bw_atual);
		}
	}

	return true;
}

void Tilemap::desenhar(RenderWindow *win)
{
	int wx, wy;
	int res_x = win->GetWidth();
	int res_y = win->GetHeight();
	wx = posicao.x;
	wy = posicao.y;
	for(int y = 0; y < ty; y++, wy+=ly)
	{
		if( (wy>-ly) && (wy<(res_y+ly)) )
			for(int x = 0; x < tx; x++, wx+=lx)
			{
				if( (wx>-lx) && (wx<(res_x+lx)) )
				{
					iSC->desenhar(win,mapa[x][y]->getTileN(),wx,wy);
				}
			}
			wx = posicao.x;
	}

	if(!nodos.empty()){
		list<Nodo*>::iterator i;
		for(i=nodos.begin(); i!=nodos.end(); i++){
			(*i)->desenhar(win);
		}
	}
}



void Tilemap::move(int dx, int dy)
{
	posicao.x += dx;
	posicao.y += dy;
}



Tile* Tilemap::getTile(int _x, int _y)
{
	return mapa[_x][_y];
}

void Tilemap::screen2map(int x, int y, int& mx, int& my)
{
	mx = x-posicao.x;
	my = y-posicao.y;
}

void Tilemap::map2screen(int x, int y, int& mx, int& my)
{
	mx = x+posicao.x;
	my = y+posicao.y;
}

int Tilemap::XparaTela(int mx)
{
	return mx+posicao.x;
}

int Tilemap::YparaTela(int my)
{
	return my+posicao.y;
}

bool Tilemap::pointColTile(int x,int y, int& cx, int& cy)
{
	if( (x<0) || (y<0) ) return false;
	if( (x >= tx*lx) || (y >= ty*ly) ) return false;
	cx = x/lx;
	cy = y/ly;
	return true;
}



// colide: somente para sprites menores que os tiles
bool Tilemap::colide(int x, int y, int w, int h)
{
	int tilx, tily;
	if(pointColTile(x,y,tilx,tily) )
	{
		if(!(mapa[tilx][tily]->getWalk())) return true;
	}
	if(pointColTile(x+w,y,tilx,tily) )
	{
		if(!(mapa[tilx][tily]->getWalk())) return true;
	}
	if(pointColTile(x,y+h,tilx,tily) )
	{
		if(!(mapa[tilx][tily]->getWalk())) return true;
	}
	if(pointColTile(x+w,y+h,tilx,tily) )
	{
		if(!(mapa[tilx][tily]->getWalk())) return true;
	}

	return false;
}


int Tilemap::getTileW()
{
	return lx;
}

int Tilemap::getTileH()
{
	return ly;
}
}