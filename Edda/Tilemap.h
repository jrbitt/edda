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


#ifndef TILEMAP_H	
#define TILEMAP_H

#  if defined(DLLMAIN_EXPORTS)
#    define DLLMAIN_API __declspec(dllexport)
#  else
#    define DLLMAIN_API __declspec(dllimport)
#  endif

#include "Camada.h"
#include "SFML\Graphics.hpp"
#include <vector>

using namespace sf;
using namespace std;

namespace Edda{
#define iSC TileCache::instance()

class DLLMAIN_API TileCache
{
public:
	void desenhar(RenderWindow *,int index,int x, int y);
	int carregar(string arquivo);
	int carregar(string arquivo, int px, int py, int largura, int altura);
	int localizar(string arquivo);
	Sprite* getImagem(int index);
	int getNumTiles();

// Singleton
	static TileCache* instance();
	static void destruir();

private:
	static TileCache* inst;
	vector<Sprite*> vetor;
	vector<Image> vetorImg;
	vector<string> mapa;
	
	TileCache();
	~TileCache();
};

class DLLMAIN_API Tile
{
private:
	int lar;
	int alt; 
	int sprite;
	int info;
	bool walkable;
	int posx;
	int posy;
public:
	Tile(void);
	~Tile(void);
	void setTile(int num_tile, int largura, int altura);
	void setWalk(bool bw);
	void setInfo(int inf);
	int getInfo();
	bool getWalk();
	int getTileN();

	int getX();
	int getY();

	friend class Tilemap;
};

class DLLMAIN_API Tilemap: public Camada{
private:
	vector<vector<Tile*> > mapa;
	string arquivo;

	int tx,ty;  // largura e altura em num. de tiles
	int lx,ly;  // tamanho de cada tile (32x32, 64x64, etc.)

public:
	Tilemap();
	~Tilemap();
	void desenhar(RenderWindow *);

	bool inicializa(string arq);
	void desenha();
	void move(int dx, int dy);
	Tile* getTile(int _x, int _y);

	void screen2map(int x, int y, int& mx, int& my);
	void map2screen(int x, int y, int& mx, int& my);
	int XparaTela(int mx);
	int YparaTela(int my);
	bool pointColTile(int x,int y, int& cx, int& cy);

	bool colide(int x, int y, int w, int h);
	int getTileW();
	int getTileH();
};
}
#endif