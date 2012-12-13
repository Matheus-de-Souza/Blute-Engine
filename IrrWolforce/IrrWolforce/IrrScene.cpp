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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111--idCounter307  USA

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

#include "IrrScene.h"
#include "IrrMesh.h"
#include "IrrCamera.h"
#include "IrrAnimatedMesh.h"
#include "IrrParticles.h"
#include "IrrGameObjectImpl.h"
#include "irrKlangSceneNode.h"

using namespace IrrWolforce;
using namespace core;
 
static int idCounter = INT_MAX;

IrrScene::IrrScene(ISceneManager *s, ISoundEngine *ss, IVideoDriver *v): Scene()
{
	this->smgr = s;
	this->soundEngine = ss;
	this->driver = v;
	this->selector = NULL;
}

GameObject *IrrScene::addCube(Vector* p, bool isCollidible)
{
	GameObject *go = new GameObject();
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setMesh(new IrrMesh(smgr->addCubeSceneNode(10.0f,((IrrGameObjectImpl*)go->getImplementor())->node,--idCounter,vector3df(p->x,p->y,p->z))));
	go->setID(idCounter);
	go->setCollidible(isCollidible);
	this->addObject(go);
	return go;
}

GameObject *IrrScene::addSphere(Vector* p, bool isCollidible)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setMesh(new IrrMesh(smgr->addSphereSceneNode(10.0f,16,((IrrGameObjectImpl*)go->getImplementor())->node,--idCounter,vector3df(p->x,p->y,p->z))));
	go->setID(idCounter);
	go->setCollidible(isCollidible);
	this->addObject(go);	
	return go;
}

GameObject *IrrScene::addCamera(Vector* p, Vector* lookAt)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setCamera(new IrrCamera(smgr->addCameraSceneNode(((IrrGameObjectImpl*)go->getImplementor())->node, vector3df(p->x,p->y,p->z), vector3df(lookAt->x,lookAt->y,lookAt->z))));
	go->setID(idCounter);
	go->setCollidible(false);
	this->addObject(go);	
	return go;
}

GameObject *IrrScene::addAnimatedMesh(char *am, Vector* p, bool isCollidible)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setAnimation(new IrrAnimatedMesh(smgr->addAnimatedMeshSceneNode(smgr->getMesh(am),
										 ((IrrGameObjectImpl*)go->getImplementor())->node,
										 --idCounter,
										 vector3df(p->x,p->y,p->z))));
	go->setID(idCounter);
	go->setCollidible(isCollidible);
	this->addObject(go);	
	return go;
}

GameObject *IrrScene::addMesh(char *m, Vector* p, bool isCollidible)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setMesh(new IrrMesh(smgr->addMeshSceneNode(smgr->getMesh(m),((IrrGameObjectImpl*)go->getImplementor())->node,--idCounter,vector3df(p->x,p->y,p->z))));
	go->setID(idCounter);
	go->setCollidible(isCollidible);
	this->addObject(go);	
	return go;
}

GameObject *IrrScene::addAudio(const char *filename,int id,Vector *p)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();

	IrrKlangSceneNode *ad;
	ad = new IrrKlangSceneNode(soundEngine,
		((IrrGameObjectImpl*)go->getImplementor())->node,
		smgr,
		id);
	ad->setSoundFileName(filename);
	go->setAudio(ad);
	go->setPosition(*p);
	
	this->addObject(go);		
	return go;
}

GameObject *IrrScene::addParticles(char *imageFileName)
{
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	go->setParticles(new IrrParticles(smgr->addParticleSystemSceneNode(false)));
	
	((IrrParticles*)go->getParticles())->node->setMaterialTexture(0, driver->getTexture(imageFileName));

	this->addObject(go);	
	return go;

}

// deve ser chamada antes de qualquer coisa ser adicionada ao grafo
void IrrScene::loadScene(char *filename)
{
	//Limpa o grafo
	smgr->clear();
	//Carrega o arquivo
	smgr->loadScene(filename);
}



int IrrScene::getNodeCount(char *name)
{
	int count = 1;
	//Cria um array para armazenar os nodos carregados do arquivo
	core::array<scene::ISceneNode *> nodes;
	//Pega todos os nodos
	smgr->getSceneNodesFromType(scene::ESNT_ANY, nodes);
	for(unsigned int i=0; i < nodes.size(); i++)
	{
		core::stringc str;
		str = name;
		str +="_";
		str += count;
		if((strcmp(nodes[i]->getName(),str.c_str()))==0) {
			count++;
		}
	}
	//retorna quantidade de nodos com aquele nome
	return count - 1;
	
}

Vector *IrrScene::getNodePosition(char *name)
{
	unsigned int nodes = getNodeCount(name);
	Vector *vec = new Vector[nodes];
	for(unsigned int i = 0; i < nodes; i++)
	{
		core::stringc str;
		str = name;
		str +="_";
		str += i+1;
		vector3df pos = smgr->getSceneNodeFromName(str.c_str())->getPosition();
		vec[i].x = pos.X; vec[i].y = pos.Y; vec[i].z = pos.Z;
		//smgr->getSceneNodeFromName(str.c_str())->remove();
		smgr->getSceneNodeFromName(str.c_str())->setMaterialFlag(video::EMF_LIGHTING, false);
		smgr->getSceneNodeFromName(str.c_str())->setMaterialFlag(video::EMF_FOG_ENABLE,true);
	}
	return vec;
}

void IrrScene::createAutomaticCollision(GameObject *_player, GameObject *_scenario, Vector center)
{
	if(selector==NULL){
 		IMeshSceneNode *cenario = ((IrrMesh*)_scenario->getMesh())->node;	
		selector = smgr->createOctTreeTriangleSelector(cenario->getMesh(), cenario, 128);
		cenario->setTriangleSelector(selector);
	}
	IAnimatedMeshSceneNode *player = ((IrrAnimatedMesh*)_player->getAnimation())->node;
    	       
	const core::aabbox3d<f32>& box = ((IrrGameObjectImpl*)_player->getImplementor())->node->getBoundingBox();
    core::vector3df radius = box.MaxEdge - box.getCenter();

    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
		selector,
		((IrrGameObjectImpl*)_player->getImplementor())->node, 
		radius,
		core::vector3df(0,-9.84,0), 
		core::vector3df(center.x,center.y,center.z));
   
	((IrrGameObjectImpl*)_player->getImplementor())->node->addAnimator(anim);
    anim->drop();
	selector->drop(); 
}

GameObject *IrrScene::addOctree(char *file){
	GameObject *go = new GameObject;
	((IrrGameObjectImpl*)go->getImplementor())->node = smgr->addEmptySceneNode();
	IAnimatedMesh* levelmesh = smgr->getMesh(file);
	go->setMesh(new IrrMesh(smgr->addOctTreeSceneNode(levelmesh)));
	this->addObject(go);	
	return go;
}