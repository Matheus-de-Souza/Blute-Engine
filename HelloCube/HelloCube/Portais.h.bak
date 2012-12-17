#pragma once

#include "Includes.h"


//////////////////////// PORTAL BRANCO /////////////////////////////

class PortalBrancoBehaviour_Nucleo : public Behavior
{				
public:
	PortalBrancoBehaviour_Nucleo();
	~PortalBrancoBehaviour_Nucleo() { }
	void update();
	Vector position;

};

class PortalBrancoBehaviour_Exterior : public Behavior
{				
public:
	PortalBrancoBehaviour_Exterior();
	~PortalBrancoBehaviour_Exterior() { }
	void update();
	Vector position;

};

class PortalBranco
{
	public:
		PortalBranco(Vector &pos, Scene *scene);
		~PortalBranco(void);
		GameObject* portalbranco_exterior;
		GameObject* portalbranco_nucleo;

	private:
		PortalBrancoBehaviour_Nucleo * portalbranconucleo_behaviour;
		PortalBrancoBehaviour_Exterior * portalbrancoexterior_behaviour;
		Scene * scene;
};



//////////////////// PORTAL PRETO ////////////////////////////



class PortalPretoBehaviour_Nucleo : public Behavior
{				
public:
	PortalPretoBehaviour_Nucleo();
	~PortalPretoBehaviour_Nucleo() { }
	void update();
	Vector position;

};

class PortalPretoBehaviour_Exterior : public Behavior
{				
public:
	PortalPretoBehaviour_Exterior();
	~PortalPretoBehaviour_Exterior() { }
	void update();
	Vector position;

};


class PortalPreto
{
	public:
		PortalPreto(Vector &pos, Scene *scene);
		~PortalPreto(void);
		GameObject* portalpreto_exterior;
		GameObject* portalpreto_nucleo;

	private:
		PortalPretoBehaviour_Nucleo * portalpretonucleo_behaviour;
		PortalPretoBehaviour_Exterior * portalpretoexterior_behaviour;
		Scene * scene;
};

