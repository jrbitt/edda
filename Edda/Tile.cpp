#include "Tilemap.h"

namespace Edda{
Tile::Tile(void)
{

}

Tile::~Tile(void)
{
}

void Tile::setTile(int num_tile, int largura, int altura)
{
	sprite = num_tile;
	lar = largura;
	alt = altura;
}

void Tile::setWalk(bool bw)
{
	walkable = bw;
}

void Tile::setInfo(int inf)
{
	info = inf;
}

int Tile::getInfo()
{
	return info;
}

bool Tile::getWalk()
{
	return walkable;
}

int Tile::getTileN()
{
	return sprite;
}

int Tile::getX()
{
	return posx;
}


int Tile::getY()
{
	return posy;
}
}