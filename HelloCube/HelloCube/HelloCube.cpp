#include <string>
#include <iostream>

#include "WolfEngine.h"
#include "IrrEngineStrategy.h"

using namespace WolfEngine;
using namespace IrrWolforce;
using namespace std;

class MyBehavior: public Behavior{
public:

        void update(){
                if(Input::getButton("fire1")){
                        gameObject->translate(5.0,0.0,0.0);
						gameObject->play();
}
                if(Input::getButton("fire2")){
                        gameObject->translate(-5.0,0.0,0.0);
						Engine::GetInstance()->setMousePosition(100,100);
                }
        }
private:
        float x;
};

class PlayerBehavior: public Behavior{
public:
    void update(){
		if(Input::getButton("fire1")){
			//gameObject->getAnimation()->play("test");
		}
		if(Input::getButton("w")){
			gameObject->translate(0.0,0.5,0.0);
		}
		if(Input::getButton("a")){
			gameObject->translate(0.0,0.0,0.5);
		}
		if(Input::getButton("s")){
			gameObject->translate(0.0,-0.5,0.0);
		}
		if(Input::getButton("d")){
			gameObject->translate(0.0,0.0,-0.5);
		}
    }
};

class BackgroundBehaviour : public Behavior
{
private:
	Vector position;

	void update()
	{
		gameObject->translate(0,0,0.1f);
		gameObject->getPosition(position);

		if ( position.z > 0.0f)
		{
			position.z = -300.0f;
			gameObject->setPosition(position);
		}
	}
};

class ObstaclesBehaviour : public Behavior
{
public:
	ObstaclesBehaviour (Vector rotationIncrement, Vector positionIncrement)
		: rotIncrement(rotationIncrement), posIncrement(positionIncrement)
	{
	}

private:
	Vector rotation;
	Vector position;

	Vector rotIncrement;
	Vector posIncrement;

	void update()
	{
		gameObject->getRotation(rotation);
		gameObject->getPosition(position);
		/*
		rotation.x = rotation.x + rotIncrement.x;
		rotation.y = rotation.y + rotIncrement.y;
		rotation.z = rotation.z + rotIncrement.z;*/

		gameObject->setRotation(rotation);
		gameObject->translate(posIncrement.x,posIncrement.y,posIncrement.z);
	}
};

void main(){
        EngineFactory::setFactory(new IrrlichtFactory);

		Input::registry("fire1",irr::KEY_LBUTTON);
		Input::registry("fire2",irr::KEY_RBUTTON);
		Input::registry("w",irr::KEY_KEY_W);
		Input::registry("a",irr::KEY_KEY_A);
		Input::registry("s",irr::KEY_KEY_S);
		Input::registry("d",irr::KEY_KEY_D);

        Engine *engine = Engine::GetInstance();

		engine->setWindowName(L"Test scene");

		//Usando scripts em Lua!
		try{
			//Teste de um arquivo de configuração
			//ScriptMachine *sm = engine->getScriptMachine();
			//sm->loadFile("../media/config.lua");
			//int v = sm->getInt("teste");
			//cout << "teste=" << v << endl;
			//GameObject *go = sm->getGameObject("go");
			//cout << "nome do go=" << *(go->getName()) << endl;

			//Fazendo setup das teclas
		//	sm->loadFile("../media/input.lua");
		}
		catch(const runtime_error& e){
			std::cout << e.what() << endl;
		}

		Scene *scene = engine->createScene();
		
		GameObject * background = scene->addAnimatedMesh("../Scenes/OBJ/Background/Background.obj",new Vector(10,5,5));
		background->setRotation(Vector(0,0,90));
		background->addBehaviour(new BackgroundBehaviour());

		GameObject *player = scene->addAnimatedMesh("../Scenes/OBJ/Player/Player.obj",new Vector(15,5,5));

		//amesh->getAnimation()->addAnimation(new AnimationEntry("test",0,50,10));
	    player->addBehaviour(new PlayerBehavior());
		player->setPosition(Vector(-25,30,-150));
		player->setRotation(Vector(0,-90,0));

		GameObject *cam = scene->addCamera(new Vector(-150,50,-150),new Vector(80,50,-150));
		cam->getCamera()->lookAt(Vector(-100,30,-150));
        cam->setName("Camera principal");

		//GameObject *a = scene->addAudio("../media/bell.wav",101,new Vector(10,0,0));
		//cube->addChild(a);
		//cube->addBehaviour(new MyBehavior());
		//cube->setActive(false);

		for(int i = 0;i != 50; ++i)
		{
			GameObject * obstacle = scene->addAnimatedMesh("../Scenes/OBJ/MeteoroM/Meteoro_M.obj",
															new Vector(-50, -100 + rand() % 200, - 500 + rand() % 1000));
			obstacle->addBehaviour(new ObstaclesBehaviour(Vector((rand() % 360) / 100.0f,(rand() % 360) / 100.0f,
																 (rand() % 360) / 100.0f), Vector(0, (- 100 + rand() % 200) / 1000.0f, ( 200 - rand() % 100) / 1000.0f)));
		}

	   engine->loop();

       delete scene;
       delete engine;
}
