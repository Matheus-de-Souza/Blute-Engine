#include "Cenario.h"

Cenario::Cenario(Vector &pos, Scene *scene)
{
	this->scene = scene;

	background_behaviour = new BackgroundBehaviour;
	Background = scene->addMesh("OBJ/Background/Background.obj",new Vector(40,-20,5));
	Background->setRotation(Vector(0,0,90));
	Background->addBehaviour(background_behaviour);
		
	//GameObject *cam = scene->addCamera(Vector(-150,50,-150),Vector(80,50,-150));

}

Cenario::~Cenario(void)
{

}

BackgroundBehaviour::BackgroundBehaviour()
{

}

void BackgroundBehaviour::update()
{
	gameObject->translate(0,0,0.1f);
	gameObject->getPosition(position);

	if ( position.z > -30.0f)
	{
		position.z = -300.0f;
		gameObject->setPosition(position);
	}
}
