#include "Edda.h"

#include <string>
using namespace std;
using namespace Edda;

int main(int argc, char** argv)
{
	Diretor *app = Diretor::getInstancia();
	app->iniciar(640,480,32,"Midgard Zombies",false);

	Cena cena;
	Camada camada(128,128,128,0);
	Edda::Sprite sprite;
	Edda::Sprite zombie;
	Tilemap map;

	camada.setPosicao(0,0);
	camada.largura = 800;
	camada.altura = 600;
	
	//sprite.carregarImagem(".\\imagens\\base.png");	
	zombie.carregarImagem(".\\imagens\\zombie.png",40,56);	
	zombie.setPosicao(0,0);

	Animacao baixoZombie;
	baixoZombie.sprite = &zombie;
	baixoZombie.adicionarFrame(new Frame(3,1000));
	baixoZombie.adicionarFrame(new Frame(4,1000));
	baixoZombie.adicionarFrame(new Frame(5,1000));
	
	AcaoAnimar andarPraBaixo(&baixoZombie);
	MoverAte mover(400,400,3000);

	Sequencia seq;		
	seq.adicionar(&andarPraBaixo);
	seq.adicionar(&mover);

	zombie.adicionarAcao(&seq);

	//zombie.adicionarAcao(&andarPraBaixoap);
	//zombie.adicionarAcao(&mover);

	map.inicializa(".\\level2.txt");
	map.setPosicao(64,32);
	map.adicionar(&zombie);
	//map.adicionar(&sprite);
	
	cena.adicionar(&map);

	app->loop(&cena);
	
	return 0;
}