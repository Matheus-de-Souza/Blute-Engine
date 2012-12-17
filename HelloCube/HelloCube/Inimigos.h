#pragma once

#include "Includes.h"


class InimigoBehaviour : public Behavior
{
public:
	InimigoBehaviour();
	~InimigoBehaviour() { }
	void update();
	short estado;
	int altura;
	bool atirando;
	clock_t start; 
	clock_t timeDiff;
};

class TiroBehaviour : public Behavior
{
public:
	TiroBehaviour();
	~TiroBehaviour() { }
	void update();
	Vector alvoPos;
	Vector normPos;
};


class Inimigo
{
public:
	Inimigo(Vector &pos, Scene * scene);
	~Inimigo(void) { }

private:
	GameObject * inimigo_o;
	Scene * scene;
	InimigoBehaviour* inimigo_behaviour; 
};

class Tiro 
{
public:
	Tiro(Vector &pos, Scene * scene);
	~Tiro(void) { }
	GameObject * tiro_o;

private:
	Scene * scene;
	TiroBehaviour* tiro_behaviour; 
};