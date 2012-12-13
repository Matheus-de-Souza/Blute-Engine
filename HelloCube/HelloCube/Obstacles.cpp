#include "Obstacles.h"

Obstacles::Obstacles(Vector &pos, Scene *scene)
{
	this->scene = scene; //copy reference
	//Obstacle = scene->addMesh("Scenes/Scenes/gera_cadeira.obj",Vector(pos.x+300, pos.y-400, pos.z));
	//Obstacle = scene->addCube(new Vector(pos.x+300, pos.y+20, pos.z));
	//Obstacle->setScale(Vector(2,2,2));
	Obstacle = scene->addAnimatedMesh("OBJ/MeteoroM/Meteoro_M.obj",
												new Vector(-100, -100 + rand() % 200, - 500 + rand() % 1000));
	Obstacle->setName("obstaculo");
	obstacle_behaviour = new ObstacleBehaviour(Vector((rand() % 360) / 100.0f,(rand() % 360) / 100.0f,
														(rand() % 360) / 100.0f), Vector(0, (- 100 + rand() % 200) / 1000.0f, ( 200 - rand() % 100) / 1000.0f));
	Obstacle->addBehaviour(obstacle_behaviour);
}

Obstacles::~Obstacles(void)
{

}

//ObstacleBehaviour::ObstacleBehaviour()
//{
//	start = clock();
//	speed = 100.0;
//	distance = 0;
//	posIni = 300;
//}
//
//void ObstacleBehaviour::update()
//{
//	timeDiff = (clock() - start);
//	start = clock();
//	dt = (float)timeDiff/1000;
//
//	distance+= speed*dt;
//
//	if(distance > posIni + 100)
//	{
//		random = rand()%800+500;
//		posIni += random;
//		gameObject->translate(random, 0.0, 0.0);
//	}
//}