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
#include "GameObject.h"
#include "WolfEngine.h"

using namespace WolfEngine;

GameObject::GameObject()
{
	this->imp = EngineFactory::getInstance()->createGameObjectImpl(this);
	this->behaviors = new vector<Behavior*>();
}

void GameObject::setName(string *n){
	this->name = n;
}

string *GameObject::getName(){
	return this->name;
}


void GameObject::setCamera(Camera *c){
	this->imp->setCamera(c);	
}

void GameObject::setMesh(Component *m){
	this->imp->setMesh(m);
}

void GameObject::setAudio(Audio *a){
	this->imp->setAudio(a);
}

void GameObject::setParticles(Particles *p)
{
	this->imp->setParticles(p);
}

Particles* GameObject::getParticles()
{
	return this->imp->getParticles();
}

Camera* GameObject::getCamera(){
	return this->imp->getCamera();
}

Audio* GameObject::getAudio(){
	return this->imp->getAudio();
}

Component* GameObject::getMesh(){
	return this->imp->getMesh();
}

void GameObject::addChild(GameObject *o)
{
	this->imp->addChild(o);
}

void GameObject::removeChild(GameObject *o)
{
	this->imp->removeChild(o);
}

GameObject *GameObject::getChild(int i)
{
	return this->imp->getChild(i);
}

int GameObject::getSize()
{
	return this->imp->getSize();
}

void GameObject::setPosition(Vector& p)
{
	this->imp->setPosition(p);
}

void GameObject::getRotation(Vector& p)
{
	this->imp->getRotation(p);
}

void GameObject::getPosition(Vector& p)
{
	this->imp->getPosition(p);
}

void GameObject::getRadius(Vector& p)
{
	this->imp->getRadius(p);
}

void GameObject::setScale(Vector& p)
{
	this->imp->setScale(p);
}

void GameObject::setRotation(Vector& p)
{
	this->imp->setRotation(p);
}

int GameObject::operator<=(const GameObject &o) const
{
	return strcmp(this->name->c_str(),o.name->c_str());
}

void GameObject::update(){
	if(this->isActive()){
		vector<Behavior*>::iterator i;
		for(i=behaviors->begin(); i!=behaviors->end(); i++){
			(*i)->update();
		}
	}
}


void GameObject::onCollide(GameObject * other){
	if(this->isActive()){
		vector<Behavior*>::iterator i;
		for(i=behaviors->begin(); i!=behaviors->end(); i++){
			(*i)->onCollide(other);
		}
	}
}

void GameObject::addBehaviour(Behavior *b){
	this->behaviors->push_back(b);
	b->setGameObject(this);
}

Behavior *GameObject::getBehavior(){
	return this->behaviors->at(0);
}

void GameObject::translate(float x, float y, float z)
{
	Vector localV;
	getPosition(localV);
	localV.x+=x;
	localV.y+=y;
	localV.z+=z;
	setPosition(localV);	
}

void GameObject::setAnimation(Animation *am){
	this->imp->setAnimation(am);
}

void GameObject::setRigidBody(RigidBody *rb)
{
	this->imp->setRigidBody(rb);
}

void GameObject::setCollider(Collider *c)
{
	this->imp->setCollider(c);
}

void GameObject::setJoint(Joint *j)
{
	this->imp->setJoint(j);
}

RigidBody *GameObject::getRigidBody()
{
	return this->imp->getRigidBody();
}
Collider *GameObject::getCollider()
{
	return this->imp->getCollider();
}
Joint *GameObject::getJoint()
{
	return this->imp->getJoint();
}

Animation* GameObject::getAnimation(){
	return this->imp->getAnimation();
}

void GameObject::setActive(bool a) {
	this->imp->setActive(a);
}	

bool GameObject::isActive() {
	return this->imp->isActive();
}

void GameObject::play()
{
	this->imp->play();	
}

bool GameObject::collide(GameObject *target)
{
	return this->imp->collide(target);
}

void GameObject::setID(int v)
{
	ID = v;
}

int GameObject::getID()
{
	return ID;
}

void GameObject::setMaterialFlag(EWolfMaterialFlag flag, bool active)
{
	this->imp->setMaterialFlag(flag,active);
}

void GameObject::remove()
{
	this->imp->remove();
}

void  GameObject::setVisible(bool isVisible)
{
	this->imp->setVisible(isVisible);
}

bool  GameObject::isVisible()
{
	return this->imp->isVisible();
}