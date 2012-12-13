//#include "Inimigos.h"
//#include "Mundo.h"
//
//Scene * cena;
//
//Inimigo::Inimigo(Vector &pos, Scene * scene)
//{
//	this->scene = scene;
//	player_o = scene->addAnimatedMesh("OBJ/Player/Player.obj",Vector(15,5,5));
//	player_behaviour = new PlayerBehaviour;
//	player_o->addBehaviour(player_behaviour);
//	player_o->setPosition(Vector(-25,30,-150));
//	player_o->setRotation(Vector(0,-90,0));
//	player_o->setName("player");
//
//		GameObject *cam = scene->addCamera(Vector(-150,50,-150),Vector(80,50,-150));
//		cam->getCamera()->lookAt(Vector(-100,30,-150));
//        cam->setName("Camera principal");
//
//	cena = scene;
//}
//
/////////////////////////////
///* PlayerBehaviour class */
/////////////////////////////
//PlayerBehaviour::PlayerBehaviour()
//{
//
//}
//
//void PlayerBehaviour::update()
//{
//			if(Input::getButton("fire1")){
//			//gameObject->getAnimation()->play("test");
//		}
//		if(Input::getButton("w")){
//			gameObject->translate(0.0,0.5,0.0);
//		}
//		if(Input::getButton("a")){
//			gameObject->translate(0.0,0.0,0.5);
//		}
//		if(Input::getButton("s")){
//			gameObject->translate(0.0,-0.5,0.0);
//		}
//		if(Input::getButton("d")){
//			gameObject->translate(0.0,0.0,-0.5);
//		}
//}