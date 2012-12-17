#pragma once

#include "Includes.h"

class PlayerBehaviour : public Behavior
{
public:
	PlayerBehaviour();
	~PlayerBehaviour() { }
	void update();
	void onCollide(GameObject * other);
	int colisoes;
	bool branco;
};

class Jogador
{
public:
	Jogador(Vector &pos, Scene * scene);
	~Jogador(void) { }
	GameObject * player_o;

private:
	Scene * scene;
	GameObject* camera;
	PlayerBehaviour* player_behaviour; 
};

class MiraBehaviour : public Behavior
{
public:
	MiraBehaviour();
	~MiraBehaviour() { }
	void update();
};

class Mira
{
public:
	Mira(Vector &pos, Scene * scene);
	~Mira(void) { }

private:
	GameObject * mira_o;
	Scene * scene;
	MiraBehaviour* mira_behaviour; 
};