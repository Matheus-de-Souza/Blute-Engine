#include "Jogador.h"
#include "Mundo.h"

Scene * cena;


Jogador::Jogador(Vector &pos, Scene * scene)
{
	this->scene = scene;
	player_o = scene->addMesh("OBJ/Player/Player.obj",new Vector(15,5,5));
	player_behaviour = new PlayerBehaviour;
	player_o->addBehaviour(player_behaviour);
	player_o->setPosition(Vector(-25,30,-100));
	player_o->setRotation(Vector(0,-90,0));
	player_o->setName("player");
	
	GameObject *cam = scene->addCamera(new Vector(-150,50,-150),new Vector(80,50,-150));
	cam->getCamera()->lookAt(Vector(-100,30,-150));
    cam->setName("Camera principal");

	cena = scene;
}

Mira::Mira(Vector &pos, Scene * scene)
{
	this->scene = scene;
	mira_o = scene->addMesh("OBJ/Mira/Mira.obj", new Vector(0,0,0), false);
	mira_behaviour = new MiraBehaviour;
	mira_o->addBehaviour(mira_behaviour);
	mira_o->setName("mira");
	
	cena = scene;
}

MiraBehaviour::MiraBehaviour()
{

}

void MiraBehaviour::update()
{
	gameObject->setPosition(Vector(Input::GetMouseX(), Input::GetMouseY(), 0));
}

///////////////////////////
/* PlayerBehaviour class */
///////////////////////////
PlayerBehaviour::PlayerBehaviour()
{
	branco = false;
}

void PlayerBehaviour::update()
{
	// teste do input do mouse
	//cout << Input::GetMouseX();
	static int tempx, tempy;
	if(Input::GetMouseClick() == 1 && branco == false){
			
			tempx = Input::GetMouseX();
			tempy = Input::GetMouseY();

			cout << "X: " << tempx << ", Y: " << tempy << endl;
			branco = true;

			PortalBranco::PortalBranco(Vector(tempx, tempy, 0.0f), cena);

		}

		if(Input::GetMouseClick() == 2){
			
			tempx = Input::GetMouseX();
			tempy = Input::GetMouseY();

			cout << "X: " << tempx << ", Y: " << tempy << endl;

			PortalPreto::PortalPreto(Vector(tempx, tempy, 0.0f), cena);

		}

		if(Input::getButton("Up")){
			gameObject->translate(0.0,0.5,0.0);
		}
		if(Input::getButton("Left")){
			gameObject->translate(0.0,0.0,0.5);
		}
		if(Input::getButton("Down")){
			gameObject->translate(0.0,-0.5,0.0);
		}
		if(Input::getButton("Right")){
			gameObject->translate(0.0,0.0,-0.5);
		}
		
		//Vector teste;
		//gameObject->getPosition(teste);

		//cout << teste.X << ", " << teste.Y << ", " << teste.Z << endl;
		
		//teste de colisao
		//if (!gameObject->TesteColision(Mundo::cenario->Background)){} else {cout << "colidindo";}
}

int count = 0;
void PlayerBehaviour::onCollide(GameObject * other)
{
	printf("%d Collidiu\n", ++count);

	if(count == 50)
		gameObject->setVisible(false);
}