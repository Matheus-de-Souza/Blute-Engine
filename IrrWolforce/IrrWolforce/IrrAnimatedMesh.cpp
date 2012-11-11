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

#include "IrrAnimatedMesh.h"
#include <locale>
#include <string>

using namespace IrrWolforce;
using namespace core;
using namespace std;

IrrAnimatedMesh::IrrAnimatedMesh(IAnimatedMeshSceneNode *c): Animation(){
	this->node = c;
	this->node->setLoopMode(false);
	this->node->setCurrentFrame(0);
	this->node->setAnimationSpeed(0);
}

void IrrAnimatedMesh::setPosition(Vector &p)
{
	this->node->setPosition(vector3df(p.x,p.y,p.z));
}

void IrrAnimatedMesh::setScale(Vector &p)
{
	this->node->setScale(vector3df(p.x,p.y,p.z));
}

void IrrAnimatedMesh::setRotation(Vector &p)
{
	this->node->setRotation(vector3df(p.x,p.y,p.z));
}

void IrrAnimatedMesh::play(char *p)
{	
	std::map<std::string, AnimationEntry*>::iterator i =	animations->find(std::string(p));
	if(i!=animations->end()){
		this->node->setLoopMode(i->second->isLoop());
		this->node->setFrameLoop(i->second->getStartFrame(), i->second->getEndFrame());
		this->node->setAnimationSpeed(i->second->getSpeed());		
	}	
}
