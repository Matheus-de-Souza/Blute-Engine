#include "Portais.h"

PortalBranco::PortalBranco(Vector &pos, Scene *scene)
{
	this->scene = scene;
	

	portalbranco_behaviour = new PortalBrancoBehaviour;
	portalbranco_o = scene->addSphere(new Vector(5.5,5.5,-55.5));
	portalbranco_o->setPosition(pos);
	portalbranco_o->addBehaviour(portalbranco_behaviour);

	

}

PortalBranco::~PortalBranco(void)
{

}

PortalBrancoBehaviour::PortalBrancoBehaviour()
{

}

void PortalBrancoBehaviour::update()
{



}



PortalPreto::PortalPreto(Vector &pos, Scene *scene)
{
	this->scene = scene;
	

	portalpreto_behaviour = new PortalPretoBehaviour;
	portalpreto_o = scene->addSphere(new Vector(5.5,5.5,-55.5));
	portalpreto_o->setPosition(pos);
	portalpreto_o->addBehaviour(portalpreto_behaviour);

	

}

PortalPreto::~PortalPreto(void)
{

}

PortalPretoBehaviour::PortalPretoBehaviour()
{

}

void PortalPretoBehaviour::update()
{



}