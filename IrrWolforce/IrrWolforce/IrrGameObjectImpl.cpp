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
-                                                                                
              Created with WolfForce Engine Project
        http://code.google.com/p/wolfengine-project/
                                                                                
    Please see the software license located at license.txt
    for more details.                                                            
                                                                                
    You should have received a copy of the License along with this software;     
    if not, write to                                                             
                                                                                
      UNISINOS
      Av. Unisinos, 950
      Bairro Cristo Rei - São Leopoldo - RS
      CEP: 93022-000-

      E-mail: jogos@unisinos.br
      Web-site: http://www.unisinos.br/jogos
*/

#include "IrrGameObjectImpl.h"
#include "IrrCamera.h"
#include "IrrMesh.h"
#include "IrrAnimatedMesh.h"
#include "irrKlangSceneNode.h"
#include "IrrParticles.h"

#include "irrlicht.h"

using namespace irr;
using namespace core;

using namespace IrrWolforce;


IrrGameObjectImpl::IrrGameObjectImpl(GameObject *o): GameObjectImpl(o){
	children = new std::map<GameObject*,ISceneNode*>();
	active = true;
}

void IrrGameObjectImpl::setPosition(Vector& p){
	node->setPosition(vector3df(p.x,p.y,p.z));
}

void IrrGameObjectImpl::getPosition(Vector& p){
	vector3df a = node->getPosition();
	p.x = a.X;
	p.y = a.Y;
	p.z = a.Z;
}

void IrrGameObjectImpl::getRadius(Vector& p){
	const core::aabbox3d<f32>& box = node->getBoundingBox();
    core::vector3df radius = box.MaxEdge - box.getCenter();	
	p.x = radius.X;
	p.y = radius.Y;
	p.z = radius.Z;
}


void IrrGameObjectImpl::getRotation(Vector& p){
	vector3df a = node->getRotation();
	p.x = a.X;
	p.y = a.Y;
	p.z = a.Z;
}

void IrrGameObjectImpl::setScale(Vector& p){
	node->setScale(vector3df(p.x,p.y,p.z));
}

void IrrGameObjectImpl::setRotation(Vector& p){
	node->setRotation(vector3df(p.x,p.y,p.z));
}

void IrrGameObjectImpl::setCamera(Camera *c)
{
	this->camera = c;
	node->addChild(((IrrCamera*)c)->node);
	((IrrCamera*)c)->node->setParent(node);
}

void IrrGameObjectImpl::setAudio(Audio *a)
{
	this->audio = a;
	node->addChild(((IrrKlangSceneNode*)a));
	((IrrKlangSceneNode*)a)->setParent(node);
}

void IrrGameObjectImpl::setParticles(Particles *c)
{
	this->particles = c;
	node->addChild(((IrrParticles*)c)->node);
	((IrrParticles*)c)->node->setParent(node);
}


void IrrGameObjectImpl::setMesh(Component *c)
{
	this->mesh = c;
	node->addChild(((IrrMesh*)c)->node);
	((IrrMesh*)c)->node->setParent(node);
}

void IrrGameObjectImpl::setAnimation(Animation *c)
{
	this->animation = c;
	node->addChild(((IrrAnimatedMesh*)c)->node);
	((IrrAnimatedMesh*)c)->node->setParent(node);
}

void IrrGameObjectImpl::setRigidBody(RigidBody *)
{
}

void IrrGameObjectImpl::setCollider(Collider *)
{
}
void IrrGameObjectImpl::setJoint(Joint *)
{
}

void IrrGameObjectImpl::addChild(GameObject *o)
{
	ISceneNode *n = ((IrrGameObjectImpl*)o->getImplementor())->node;
	children->insert(std::pair<GameObject*,ISceneNode*>(o,n));
	node->addChild(n);
	n->setParent(node);
}

void IrrGameObjectImpl::removeChild(GameObject *o)
{	
	node->removeChild(children->at(o));
}

GameObject *IrrGameObjectImpl::getChild(int i)
{
	return (children->begin())->first;
}

int IrrGameObjectImpl::getSize()
{
	return children->size();
}

void IrrGameObjectImpl::setActive(bool a)
{
	active = a;
}

bool IrrGameObjectImpl::isActive()
{
	return active;
}

void IrrGameObjectImpl::play()
{
	audio->setPlayOnceMode(true);
}

void IrrGameObjectImpl::setMaterialFlag(EWolfMaterialFlag flag, bool active)
{
	int aux = (int)flag;
	video::E_MATERIAL_FLAG mat = (video::E_MATERIAL_FLAG)aux;
	if( this->getMesh() != NULL ){
		if( this->getAnimation() != NULL ){
			((IrrAnimatedMesh *)this->getAnimation())->node->setMaterialFlag( mat,active);
		} 
		else {
			((IrrMesh *)this->getMesh())->node->setMaterialFlag( mat,active);
		}
	}

}

void IrrGameObjectImpl::setVisible(bool isVisible)
{
	this->node->setVisible(isVisible);
}

bool IrrGameObjectImpl::isVisible()
{
	return this->node->isVisible();
}

void IrrGameObjectImpl::setCollidible(bool collidible)
{
	this->collidible = collidible;
}

bool IrrGameObjectImpl::isCollidible()
{
	return this->collidible;
}

bool IrrGameObjectImpl::collide(GameObject *o)
{
	aabbox3d<f32> nodeTarget;
	aabbox3d<f32> myNode;
	if(o->getMesh()!=NULL)
	{
		nodeTarget =((IrrMesh *)o->getMesh())->node->getBoundingBox();
	}
	else if(o->getAnimation()!=NULL){
		nodeTarget =((IrrAnimatedMesh *)o->getAnimation())->node->getBoundingBox();
	}

	if(getMesh()!=NULL)
	{
		myNode =((IrrMesh *)getMesh())->node->getBoundingBox();
	}
	else if(getAnimation()!=NULL){
		myNode =((IrrAnimatedMesh *)getAnimation())->node->getBoundingBox();
	}

	if(!myNode.isEmpty() && !nodeTarget.isEmpty()){
		return myNode.intersectsWithBox(nodeTarget);
	}
	else{
		return false;
	}
}

void IrrGameObjectImpl::remove()
{
	this->node->remove();
	this->node = NULL;
	active = false;
}