#pragma once

#include "Includes.h"

class BackgroundBehaviour : public Behavior
{				
public:
	BackgroundBehaviour();
	~BackgroundBehaviour() { }
	void update();
	Vector position;

};


class Cenario
{
	public:
		Cenario(Vector &pos, Scene *scene);
		~Cenario(void);
		GameObject * Background;

	private:
		BackgroundBehaviour * background_behaviour;
		Scene * scene;
};

