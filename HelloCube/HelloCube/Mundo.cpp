#include "Mundo.h"

Engine* Mundo::engine = 0;
Jogador* Mundo::jogador = 0;
Cenario* Mundo::cenario = 0;
GameObject* Mundo::obstacles = 0;
//PortalBranco* Mundo::portalbranco = 0;
//PortalPreto* Mundo::portalpreto = 0;
Mira* Mundo::mira = 0;
//Scene* World::scene = 0;
ObstacleBehaviour *Mundo::obstacle_behaviour = 0;

Mundo::Mundo(void)
{
}

Mundo::~Mundo(void)
{
}

void Mundo::Iniciar()
{
	WolfEngine::EngineFactory::setFactory(new IrrWolforce::IrrlichtFactory);

	engine = Engine::GetInstance();

	Input::registry("Right",irr::KEY_KEY_D);
	Input::registry("Left",irr::KEY_KEY_A);
	Input::registry("Up",irr::KEY_KEY_W);
	Input::registry("Down",irr::KEY_KEY_S);

	engine->setWindowName(L"Blute Hole");

	Scene * scene = engine->createScene();
	
	jogador = new Jogador(Vector(0,0,0),scene);
	cenario = new Cenario(Vector(0,0,0),scene);
	mira = new Mira(Vector(0,0,0),scene);
	//portalbranco = new PortalBranco(Vector(0,0,0), scene);
	//portalpreto = new PortalPreto(Vector(0,0,0), scene);
	//obstacles = scene->addCube(Vector(300, 20, 0.0));
	obstacle_behaviour = new ObstacleBehaviour;
	for(int i = 0;i != 10; ++i)
	{
		GameObject * obstacle = scene->addMesh("OBJ/MeteoroM/Meteoro_M.obj",
												new Vector(-50, -100 + rand() % 200, - 500 + rand() % 1000));
		obstacle->setName("obstaculo");
		obstacle->addBehaviour(new ObstacleBehaviour(Vector((rand() % 360) / 100.0f,(rand() % 360) / 100.0f, (rand() % 360) / 100.0f),
													 Vector(0, (- 100 + rand() % 200) / 1000.0f, ( 200 - rand() % 100) / 1000.0f)));
	}
	
	Loop();
}

void Mundo::Loop()
{
	// init engine
	engine->loop();
}

void Mundo::Fim()
{
	//delete scene;
	//delete engine;
	Iniciar();
}