#include "Portais.h"

PortalBranco::PortalBranco(Vector &pos, Scene *scene)
{
	this->scene = scene;
	
	portalbranconucleo_behaviour = new PortalBrancoBehaviour_Nucleo;
	portalbranco_nucleo = scene->addSphere(new Vector(5.5,5.5,5.5));
	portalbranco_nucleo->setName("Portal Branco Nucleo");
	portalbranco_nucleo->setPosition(pos);
	portalbranco_nucleo->addBehaviour(portalbranconucleo_behaviour);

	portalbrancoexterior_behaviour = new PortalBrancoBehaviour_Exterior;
	portalbranco_exterior = scene->addSphere(new Vector(10.0,10.0,10.0));
	portalbranco_exterior->setName("Portal Branco Exterior");
	portalbranco_exterior->setPosition(pos);
	portalbranco_exterior->addBehaviour(portalbrancoexterior_behaviour);
}

PortalBranco::~PortalBranco(void)
{

}

PortalBrancoBehaviour_Nucleo::PortalBrancoBehaviour_Nucleo()
{

}

void PortalBrancoBehaviour_Nucleo::update()
{



}

PortalBrancoBehaviour_Exterior::PortalBrancoBehaviour_Exterior()
{

}

void PortalBrancoBehaviour_Exterior::update()
{



}


PortalPreto::PortalPreto(Vector &pos, Scene *scene)
{
	this->scene = scene;

	portalpretonucleo_behaviour = new PortalPretoBehaviour_Nucleo;
	portalpreto_nucleo = scene->addSphere(new Vector(0.5,0.5,0.5));
	portalpreto_nucleo->setName("Portal Negro Nucleo");
	portalpreto_nucleo->addBehaviour(portalpretonucleo_behaviour);

	portalpretoexterior_behaviour = new PortalPretoBehaviour_Exterior;
	portalpreto_exterior = scene->addSphere(new Vector(3.0,3.0,3.0));
	portalpreto_exterior->setName("Portal Negro Exterior");
	portalpreto_exterior->addBehaviour(portalpretoexterior_behaviour);
}

PortalPreto::~PortalPreto(void)
{

}

PortalPretoBehaviour_Nucleo::PortalPretoBehaviour_Nucleo()
{

}

void PortalPretoBehaviour_Nucleo::update()
{



}

PortalPretoBehaviour_Exterior::PortalPretoBehaviour_Exterior()
{

}

void PortalPretoBehaviour_Exterior::update()
{



}