#ifndef MUNDO
#define MUNDO

#include "Includes.h"
#include "Jogador.h"
#include "Inimigos.h"
#include "Cenario.h"
#include "Portais.h"
#include "Obstacles.h"
#include "GUIBehaviour.h"

class Mundo
{
public:
	~Mundo(void);
	static void Iniciar();
	//static void MenuPrincipal();
	static void Loop();
	static void Fim();
	static GameObject *obstacles;
	static ObstacleBehaviour *obstacle_behaviour;
	static Cenario *cenario;
	static Jogador *jogador;
	static Tiro *tiro;
	static PortalBranco *portalbranco;
	static PortalPreto *portalpreto;

private:
	Mundo(void);
	static Inimigo *inimigo;
	static Mira *mira;
	static Engine *engine;
	static Scene * scene;
};

#endif