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
#ifndef PHYSICS_H
#define PHYSICS_H
#include "dllDefine.h"
#include "Component.h"
#include "Vector.h"

namespace WolfEngine{
	//afeta o objeto pela gravidade
	//calcula como o objeto responde a colisão
	class WOLFORCE_API RigidBody: public Component{
	protected:
		Vector *velocity;
		Vector *angVelocity;
		float mass;
		bool useGravity;
	public:
		void setVelocity(Vector *v) {velocity =v;}
		void setAngularVelocity(Vector *v) {angVelocity =v;}
		void setMass(float m) {mass = m;}
		void setGravity(bool b) {useGravity = b;}

		Vector *getVelocity() {return velocity;}
		Vector *getAngularVelocity() {return angVelocity;}
		float getMass() {return mass;}
		bool getGravity() {return useGravity;}
	};

	class WOLFORCE_API PhysicMaterial{
	public:
		float restituition;
		float staticFriction;
		float dynamicFriaction;
	};

	class WOLFORCE_API Collider: public Component{
	private:
		PhysicMaterial *material;
	public:
		void setMaterial(PhysicMaterial *v){ material = v;}
		PhysicMaterial* getMaterial(){return material;}
	};

	class WOLFORCE_API BoxCollider: public Collider{
	private:
		Vector *center;
		Vector *size;
	public:
		BoxCollider(Vector *c, Vector *s){
			center = c;
			size = s;
		}
		void setCenter(Vector *v){ center = v;}
		void setSize(Vector *v){ size = v;}
		Vector* getCenter(){return center;}
		Vector* getSize(){ return size;}
	};

	class WOLFORCE_API Joint: public Component{
	private:
		RigidBody *from;
		RigidBody *to;
	public:
		Joint(RigidBody *from, RigidBody *to);
		RigidBody *getFromBody(){return from;}
		RigidBody *getToBody(){return to;}
	};

}
#endif