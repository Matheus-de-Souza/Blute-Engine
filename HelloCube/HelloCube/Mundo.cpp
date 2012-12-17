#include "Mundo.h"

Scene* Mundo::scene = 0;
Engine* Mundo::engine = 0;
Jogador* Mundo::jogador = 0;
Inimigo* Mundo::inimigo = 0;
Tiro* Mundo::tiro = 0;
Cenario* Mundo::cenario = 0;
GameObject* Mundo::obstacles = 0;
PortalBranco* Mundo::portalbranco = 0;
PortalPreto* Mundo::portalpreto = 0;
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
	Input::registry("Escape",irr::KEY_ESCAPE);
	Input::registry("Credits",irr::KEY_KEY_C);
	Input::registry("Init",irr::KEY_KEY_I);

	scene = engine->createScene();
	
	jogador = new Jogador(Vector(0,0,0),scene);
	cenario = new Cenario(Vector(0,0,0),scene);
	inimigo = new Inimigo(Vector(0,0,0),scene);
	mira = new Mira(Vector(0,0,0),scene);
	portalbranco = new PortalBranco(Vector(0,0,0), scene);
	portalpreto = new PortalPreto(Vector(0,0,0), scene);
	//obstacles = scene->addCube(Vector(300, 20, 0.0));
	obstacle_behaviour = new ObstacleBehaviour;
		for(int i = 0;i != 10; ++i)
		{
			GameObject * obstacle = scene->addMesh("../Scenes/OBJ/MeteoroM/Meteoro_M.obj",new Vector(0.0,0.0,0.0));
			obstacle->setName("obstaculo");
			obstacle->addBehaviour(obstacle_behaviour);
		}

	GUIEnvironment * gui = engine->getGUIEnvironment();

	//gui->loadImage("main","../Scenes/GUI/Telas/Tela_Menu.jpg");
	//gui->loadImage("credits","../Scenes/GUI/Telas/Creditos.jpg");
	//gui->addImage("credits","credits",0,0);
	//gui->addImage("main","main",0,0);
	//
	//gui->makeInvisible("credits");
	//gui->makeVisible("main");

	GameObject * g = scene->addCube(new Vector(0,0,0),false);
	g->addBehaviour(new GuiBehaviour(gui));
	Iniciar();
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