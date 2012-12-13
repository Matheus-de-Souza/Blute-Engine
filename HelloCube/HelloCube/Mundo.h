#include "Includes.h"
#include "Jogador.h"
#include "Cenario.h"
#include "Portais.h"
#include "Obstacles.h"

class Mundo
{
public:
	~Mundo(void);
	static void Iniciar();
	static void Loop();
	static void Fim();
	static GameObject *obstacles;
	static ObstacleBehaviour *obstacle_behaviour;
	static Cenario *cenario;
	static PortalBranco *portalbranco;
	static PortalPreto *portalpreto;

private:
	Mundo(void);
	static Jogador *jogador;
	static Mira *mira;
	static Engine *engine;
};