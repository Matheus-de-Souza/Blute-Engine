#pragma once

#include "Includes.h"

class ObstacleBehaviour : public Behavior
{
public:
	ObstacleBehaviour (){}
	ObstacleBehaviour (Vector rotationIncrement, Vector positionIncrement)
		: rotIncrement(rotationIncrement), posIncrement(positionIncrement)
	{
	}

private:
	Vector rotation;
	Vector position;

	Vector rotIncrement;
	Vector posIncrement;
public:
	void update()
	{
		gameObject->getRotation(rotation);
		gameObject->getPosition(position);

		/*
		rotation.x = rotation.x + rotIncrement.x;
		rotation.y = rotation.y + rotIncrement.y;
		rotation.z = rotation.z + rotIncrement.z;*/

		gameObject->setRotation(rotation);
		gameObject->translate(posIncrement.x,posIncrement.y,posIncrement.z);
	}
};

class Obstacles 
{
	public:
		Obstacles(Vector &pos, Scene *scene);
		~Obstacles();

	private:
		GameObject * Obstacle;
		Scene * scene;
		ObstacleBehaviour *obstacle_behaviour;
};