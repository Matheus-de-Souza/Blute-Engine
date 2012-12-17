#include "Inimigos.h"
#include "Mundo.h"

Scene *cena_;

Inimigo::Inimigo(Vector &pos, Scene *scene)
{
	this->scene = scene;
	inimigo_o = scene->addAnimatedMesh("../Scenes/OBJ/Inimigo/Inimigo.obj",new Vector(0,0,0));
	inimigo_behaviour = new InimigoBehaviour;
	inimigo_o->addBehaviour(inimigo_behaviour);
	inimigo_o->setPosition(Vector(-75,0,-325));
	inimigo_o->setRotation(Vector(0,180,0));
	inimigo_o->setName("inimigo");

	cena_ = scene;
}

InimigoBehaviour::InimigoBehaviour()
{
	estado = 0;
	altura = 0; 
	atirando = false;
	start = clock();
}

float round(float r) 
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

float getMagnitude(Vector& p)
{
        float magnitude = sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
        return magnitude;
}

Vector normalize(Vector& p)
{
        float length =	getMagnitude(p);
        Vector temp = p;
        temp.x = temp.x / length;
		temp.y = temp.y / length;
		temp.z = temp.z / length;
        return temp;
}

void InimigoBehaviour::update()
{
  timeDiff = (clock() - start);
  Vector targetPos, nodePos, myPos, myRot; 
  gameObject->getRotation(myRot);
  gameObject->getPosition(myPos);
  Mundo::jogador->player_o->getPosition(targetPos);

  switch(estado){

  case 0:
	  // Inicialização da IA
	  gameObject->setPosition(Vector(-700, rand() % 600, -325));
	  estado = 1;
	  break;
  case 1:
	  // Ajuste de Posição para dentro da tela
	  if (myPos.x < -100)
	  {  gameObject->translate(0.5,0,0);  }
	  else{ estado = 2; start = clock(); }
	  break;
  case 2:
	  // Inimigo mira no jogador
	  if (timeDiff < 1000)
	  {
	    nodePos.x = targetPos.x - myPos.x;
		nodePos.y = targetPos.y - myPos.y;
		nodePos.z = targetPos.z - myPos.z;   

		  myRot.z = atan(nodePos.z/nodePos.x) * (180.0f / irr::core::PI);
		  if ((targetPos.x - myPos.x) > 0)
		  {
			  myRot.y = 90 - myRot.y;
		  } 
		  else if ((targetPos.x - myPos.x) < 0)
		{
			myRot.y = -90 - myRot.y;
			}
		myRot.y -= 90;
		gameObject->setRotation(myRot);
		break;
	  }
	  else 
	  {
	  start = clock();
	  estado = 3;
	  }
	  break;
  case 3:
	  // esperar meio segundo
	  if (timeDiff < 1500)
	  {
		  break;
	  }
	  else { estado = 4; }
	  break;
  case 4:
	  // atirar
	  atirando = TRUE;
	  start = clock();
	  estado = 5;
	  break;
  case 5:
	  // esperar 1 segundo
	  if (timeDiff < 1000)
	  {
		  break;
	  }
	  else
	  {
		  altura = (rand() % 300) - 150;
		  estado = 6;
	  }
	  break;
  case 6:
	//   reajustar
	  float tempY;
	  tempY = round(myPos.y);
	  float altura_ = altura;
	  if (altura_ == tempY)
	  {
		  estado = 2;
		  break;
	  }
	  else if (altura_ > tempY)
	  { gameObject->translate(0,1,0); }
	  else if (altura_ < tempY)
	  { gameObject->translate(0,-1,0); }

	  Vector teste;
	  gameObject->getPosition(teste);
	  cout << teste.y << endl;
  }

  if (atirando == true)
  {
	  //inimigo = new Inimigo(Vector(0,0,0),scene);
	  Mundo::tiro = new Tiro(myPos, cena_);
	  atirando = false;
  }

 //cout << timeDiff << ", " << estado << endl;
  //gameObject->translate(0.2,0,0);
}

Tiro::Tiro(Vector &pos, Scene *scene)
{
	this->scene = scene;
	tiro_o = scene->addSphere(&pos);
	tiro_behaviour = new TiroBehaviour;
	tiro_o->addBehaviour(tiro_behaviour);
	tiro_o->setPosition(pos);
	tiro_o->setName("tiro");

	cena_ = scene;
}

TiroBehaviour::TiroBehaviour()
{
	Mundo::jogador->player_o->getPosition(alvoPos);
	normPos = (0,0,0);
}

void TiroBehaviour::update()
{
  Vector myPos;
  gameObject->getPosition(myPos);
	 	normPos.x = alvoPos.x - myPos.x;
		normPos.y = alvoPos.y - myPos.y;
		normPos.z = alvoPos.z - myPos.z;   

	normPos = normalize(normPos);	
	gameObject->translate(normPos.x, normPos.y, normPos.z);
	if (myPos.x == alvoPos.x)
	{
		gameObject->remove();
	}
}
