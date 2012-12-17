#pragma once

#include "Includes.h"


//////////////////////// PORTAL BRANCO /////////////////////////////

class PortalBrancoBehaviour : public Behavior
{				
public:
	PortalBrancoBehaviour();
	~PortalBrancoBehaviour() { }
	void update();
	Vector position;

};


class PortalBranco
{
	public:
		PortalBranco(Vector &pos, Scene *scene);
		~PortalBranco(void);
		GameObject* portalbranco_o;

	private:
		PortalBrancoBehaviour * portalbranco_behaviour;
		Scene * scene;
};




class PortalPretoBehaviour : public Behavior
{				
public:
	PortalPretoBehaviour();
	~PortalPretoBehaviour() { }
	void update();
	Vector position;

};


class PortalPreto
{
	public:
		PortalPreto(Vector &pos, Scene *scene);
		~PortalPreto(void);
		GameObject* portalpreto_o;

	private:
		PortalPretoBehaviour * portalpreto_behaviour;
		Scene * scene;
};