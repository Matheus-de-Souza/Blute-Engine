/*
    WolfForce Engine Project - 3D Game Engine Project
    Copyright (C) 2011  João Ricardo Bittencourt <joaorb@unisinos.br>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    For the purposes of the WolfForce Engine Project software we request that 
	software using or linking this engine or its libraries display the
    following notice:                                                            
                                                                                
              Created with WolfForce Engine Project
        http://code.google.com/p/wolfengine-project/
                                                                                
    Please see the software license located at license.txt
    for more details.                                                            
                                                                                
    You should have received a copy of the License along with this software;     
    if not, write to                                                             
                                                                                
      UNISINOS
      Av. Unisinos, 950
      Bairro Cristo Rei - São Leopoldo - RS
      CEP: 93022-000

      E-mail: jogos@unisinos.br
      Web-site: http://www.unisinos.br/jogos
*/
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "dllDefine.h"
#include <string>
#include <vector>

#include "Camera.h"
#include "Behavior.h"
#include "Animation.h"
#include "Audio.h"
#include "Physics.h"
#include "Particles.h"

using namespace std;

namespace WolfEngine{	
	enum WOLFORCE_API EWolfMaterialFlag
	{
		EWMF_FOG_ENABLE = 2048
	};

	class Component;

	class WOLFORCE_API GameObjectImpl{
	public:
		GameObjectImpl(GameObject *o) {gameObject = o;}

		virtual void remove()=0;
		virtual void setMaterialFlag(EWolfMaterialFlag flag, bool active)=0;

		virtual void setPosition(Vector&) = 0;
		virtual void setScale(Vector&) = 0;
		virtual void setRotation(Vector&) = 0;
		virtual void getPosition(Vector&) = 0;
		virtual void getRotation(Vector&) = 0;
		virtual void getRadius(Vector&) = 0;

		virtual void setCamera(Camera *) = 0;
		virtual void setMesh(Component *) = 0;
		virtual void setAnimation(Animation *)=0;
		virtual void setAudio(Audio *) =0;
		virtual void setRigidBody(RigidBody *) =0;
		virtual void setCollider(Collider *) =0;
		virtual void setJoint(Joint *) =0;
		virtual void setParticles(Particles *)=0;

		virtual Camera* getCamera() = 0; 
		virtual Animation* getAnimation() = 0; 
		virtual Component* getMesh() = 0;
		virtual Audio* getAudio() =0;
		virtual RigidBody * getRigidBody() =0;
		virtual Collider * getCollider() =0;
		virtual Joint * getJoint() =0;		
		virtual Particles* getParticles()=0;

		virtual void addChild(GameObject *o) = 0;
		virtual void removeChild(GameObject *o) = 0;
		virtual GameObject *getChild(int) = 0;
		virtual  int getSize() = 0;

		virtual void setActive(bool a) = 0;
		virtual bool isActive() = 0;
		virtual void play() = 0;

		virtual void setVisible(bool isVisible)=0;
		virtual bool isVisible()=0;

		virtual void setCollidible(bool) = 0;
		virtual bool isCollidible() = 0;

		virtual bool collide(GameObject *) = 0;
		
		GameObject *gameObject;
	};

	class WOLFORCE_API GameObject{
	public:
		GameObject();

		void remove();
		void setMaterialFlag(EWolfMaterialFlag flag, bool active);

		void setPosition(Vector&);
		void setScale(Vector&);
		void setRotation(Vector&);		
		void getPosition(Vector&);
		void getRotation(Vector&);
		void getRadius(Vector&);

		void setName(string*);
		void setName(const char*s){setName(new string(s));}
		string *getName();	

		void setCamera(Camera *);
		void setMesh(Component *);		
		Camera* getCamera(); 
		void setAnimation(Animation *);
		Animation* getAnimation();
		Component* getMesh(); 
		void setAudio(Audio *);
		Audio *getAudio();
		void setParticles(Particles *);
		Particles* getParticles();
		void setRigidBody(RigidBody *);
		void setCollider(Collider *);
		void setJoint(Joint *);
		RigidBody * getRigidBody();
		Collider * getCollider();
		Joint * getJoint();

		void addChild(GameObject *o);
		void removeChild(GameObject *o);
		GameObject *getChild(int);
		int getSize();

		bool collide(GameObject *);

		GameObjectImpl *getImplementor() {return imp;}
		void setActive(bool a);	
		bool isActive();
		void setVisible(bool);
		bool isVisible();
		
		void setCollidible(bool);
		bool isCollidible();

		void onCollide(GameObject * other);
		void update();
		void addBehaviour(Behavior *);
		Behavior *getBehavior();

		void translate(float x, float y, float z);
		void play();

		int operator<=(const GameObject &) const;
		bool operator==(GameObject *b){
			return this->ID == b->ID;
		}

		int getID();
		void setID(int);

	private:
		string *name;
		int ID;
		GameObjectImpl *imp;

		vector<Behavior*> *behaviors;
	};
}
#endif