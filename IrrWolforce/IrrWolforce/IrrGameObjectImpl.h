#ifndef IRR_GAME_OBJ_H
#define IRR_GAME_OBJ_H
/*
    WolfForce Engine Project - 3D Game Engine Project
	IrrWolforce - Irrlicht eXtension for WolfForce Engine Project
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

#include <map>

#include "irrlicht.h"

#include "GameObject.h"

#include "Camera.h"
#include "Animation.h"
#include "Audio.h"
#include "Physics.h"

using namespace irr;
using namespace scene;
using namespace std;

using namespace WolfEngine;
#include "dllIrrDefine.h"
namespace IrrWolforce{
	class IRRWOLFORCE_API IrrGameObjectImpl: public GameObjectImpl{
	public:
		IrrGameObjectImpl(GameObject *o);

		void remove();
		void setMaterialFlag(EWolfMaterialFlag flag, bool active);

		void setPosition(Vector&);
		void setScale(Vector&);
		void setRotation(Vector&);
		void getPosition(Vector&);
		void getRotation(Vector&);
		void getRadius(Vector&);

		void setCamera(Camera *);
		void setMesh(Component *);		
		Camera* getCamera() {return camera;} 
		Component* getMesh() {return mesh;}
		void setAnimation(Animation *);
		Animation* getAnimation() {return animation;}
		void setAudio(Audio *);
		Audio* getAudio() {return audio;}
		void setRigidBody(RigidBody *);
		void setCollider(Collider *);
		void setJoint(Joint *);
		RigidBody * getRigidBody() {return body;}
		Collider * getCollider() {return collider;}
		Joint * getJoint() {return joint;}

		void setParticles(Particles *);
		Particles* getParticles() { return particles;}

		void addChild(GameObject *o);
		void removeChild(GameObject *o);
		GameObject *getChild(int);
		int getSize();

		void setActive(bool a);	
		bool isActive();
		void setVisible(bool isVisible);
		bool isVisible();

		void play();

		bool collide(GameObject *o);

		ISceneNode *node;				
		GameObject *gameObject;
	private:
		bool active;

		Camera *camera;
		Component *mesh;
		Animation *animation;
		Audio *audio;
		RigidBody *body;
		Collider *collider;
		Joint *joint;
		Particles *particles;
		std::map<GameObject*,ISceneNode*> *children;
	};
}
#endif