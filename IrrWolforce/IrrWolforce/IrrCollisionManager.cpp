#include "IrrCollisionManager.h"
#include "IrrLevel.h"
#include "IrrGameObjectImpl.h"
#include "IrrAnimatedMesh.h"
#include "IrrMesh.h"

#include <iostream>

#include <stdio.h>
#include <windows.h>
#include <process.h> 

using namespace IrrWolforce;

IrrCollisionManager::IrrCollisionManager(IrrlichtDevice *d)
{
	this->device = d;
	smgr = device->getSceneManager();
}

void IrrCollisionManager::setCollider(GameObject *level, bool opt){
	//cria como octree
	ITriangleSelector* selector = 0;
	ISceneNode *node = ((IrrGameObjectImpl*)level->getImplementor())->node;
	if(opt){		
		IAnimatedMeshSceneNode *levelMeshNode = ((IrrAnimatedMesh *)level->getAnimation())->node;
		selector = smgr->createOctreeTriangleSelector(
			levelMeshNode->getMesh(),
			node, 
			128);
	}
	else{
		selector = smgr->createTriangleSelectorFromBoundingBox(node);		
	}
	//Adiciona o seletor no nodo
	node->setTriangleSelector(selector);
	selector->drop();
}

void IrrCollisionManager::addResponse(GameObject *level, GameObject *target,  Vector radius, Vector offset){
	IAnimatedMeshSceneNode *node = ((IrrAnimatedMesh *)level->getImplementor()->getAnimation())->node;
	//ISceneNode *trg = ((IrrGameObjectImpl*)target->getImplementor()->getAnimation())->node;

	IAnimatedMeshSceneNode *meshNode = ((IrrAnimatedMesh *)target->getImplementor()->getAnimation())->node;
    ISceneNode *sceneNode = ((IrrGameObjectImpl*)target->getImplementor())->node;
	
	ITriangleSelector *selector = node->getTriangleSelector();
	
	if(selector){
		ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
                        selector, 
						meshNode, 
						irr::core::vector3df(radius.x,radius.y,radius.z),
                        irr::core::vector3df(0,-10,0),
						irr::core::vector3df(offset.x,offset.y,offset.z));
		//Adiciona a animacao
		sceneNode->addAnimator(anim);
		anim->drop();
		selector->drop();
	}
}

void IrrCollisionManager::createLevel(GameObject *target){
	IAnimatedMeshSceneNode *scene = ((IrrAnimatedMesh*)target->getAnimation())->node;
	smgr->addOctreeSceneNode(scene->getMesh());			
	this->setCollider(target,true);
}

void IrrCollisionManager::checkCollisions(std::vector<GameObject*> & objects)
{
	//vector<GameObject*>::iterator i;
	//vector<GameObject*>::iterator j;
	
	core::aabbox3d<f32> boundingBox1;
	core::aabbox3d<f32> boundingBox2;
	
	bool collided = false;

	GameObject * i;
	GameObject * j;

	//for(i=objects->begin(); i!=objects->end(); i++)
	//{
	//	for(j=objects->begin(); j!=objects->end(); j++)
	//	{
	int nObjects = objects.size();
	for(int a = 0; a != nObjects; ++a)
	{
		for(int b = 0; b != nObjects; ++b)
		{			
			i = objects[a];
			j = objects[b];

						if(i->getID() == j->getID() || !i->isCollidible() || !j->isCollidible())
			{
				//printf("%s - %s\n", i->getName() , j->getName());
				continue;
			}

			if(i->getMesh()!=NULL){
				boundingBox1 =((IrrMesh *)i->getMesh())->node->getTransformedBoundingBox();
			}
			else if(i->getAnimation()!=NULL){
				boundingBox1 =((IrrAnimatedMesh *)i->getAnimation())->node->getTransformedBoundingBox();
			}

			if(j->getMesh()!=NULL){
				boundingBox2 =((IrrMesh *)j->getMesh())->node->getTransformedBoundingBox();
			}
			else if(j->getAnimation()!=NULL){
				boundingBox2 =((IrrAnimatedMesh *)j->getAnimation())->node->getTransformedBoundingBox();
			}

			if(!boundingBox1.isEmpty() && !boundingBox2.isEmpty()){
				collided = boundingBox1.intersectsWithBox(boundingBox2);	
			}
			
			if(collided){
				//printf("%s e %s\n", i->getName(), *j->getName());
				i->onCollide(j);
				j->onCollide(i);
			}
		}
	}		
}

/*
void IrrCollisionManager::setSelectors()
{
}


void IrrCollisionManager::setSelector(GameObject *go)
{
    
}

void IrrCollisionManager::addLevelSelector(Level *l)
{
    
    levelMeshNode = ((IrrLevel*)(l))->getThisMesh();

    if (levelMeshNode)
	{
		selector = smgr->createOctreeTriangleSelector(
				levelMeshNode->getMesh(), levelMeshNode, 128);
		levelMeshNode->setTriangleSelector(selector);		
		selector->drop();
	}
}

void IrrCollisionManager::addLevelSelector(GameObject *go)
{
    levelMeshNodeX  = ((IrrGameObjectImpl*)go->getImplementor())->node;
	levelMeshNode = ((IrrMesh *)go->getMesh())->node;

	selector =  smgr->createOctreeTriangleSelector(
		levelMeshNode->getMesh(), levelMeshNode, 128);
	levelMeshNodeX->setTriangleSelector(selector);

	selector->drop();
}


void IrrCollisionManager::addSelectorToGameObject(GameObject *go)
{
    IAnimatedMeshSceneNode *meshNode = ((IrrAnimatedMesh *)go->getImplementor()->getAnimation())->node;
    selector = smgr->createTriangleSelectorFromBoundingBox(meshNode);
    meshNode->setTriangleSelector(selector);

	selector->drop();
}

void IrrCollisionManager::addToMetaSelector(GameObject *go, char *p)
{
    map<char *, IMetaTriangleSelector *>::iterator it;
    IAnimatedMeshSceneNode *meshNode = ((IrrAnimatedMesh *)go->getImplementor()->getAnimation())->node;

    printf ("METANAME: %s", p);


    int i = 0;
    for(it = metaSelectors->begin(); (it != metaSelectors->end() && i < metaSelectors->size()); it++)
    {
        if(it->first == p)
        {
            printf("\n meta encontrado \n");

            it->second->addTriangleSelector(meshNode->getTriangleSelector());
            break;
        }
        else if(i == (metaSelectors->size()-1))
        {            
            printf("\n novo metaaaaaaaaaaaaaaaaa \n");

            IMetaTriangleSelector *metaSel;
            metaSel = smgr->createMetaTriangleSelector();
            metaSel->addTriangleSelector(levelMeshNodeX->getTriangleSelector());
            metaSel->addTriangleSelector(meshNode->getTriangleSelector());

            metaSelectors->insert( pair<char *, IMetaTriangleSelector *>(p, metaSel));
        }
        i++;
    }  
}


void IrrCollisionManager::addMetaToGameObject(char *p, GameObject *go)
{
    IAnimatedMeshSceneNode *meshNode = ((IrrAnimatedMesh *)go->getImplementor()->getAnimation())->node;
    ISceneNode *sceneNode = ((IrrGameObjectImpl*)go->getImplementor())->node;


    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
													    metaSelectors->find(p)->second, meshNode, core::vector3df(1.f,1.f,2.f),
														core::vector3df(0,-10,0), core::vector3df(0,0,0));
    sceneNode->addAnimator(anim);				
    anim->drop();
}

bool IrrCollisionManager::getCollisionFromBB(GameObject *go1, GameObject *go2)
{

	core::aabbox3d<f32> go1BB;
	core::aabbox3d<f32> go2BB;

	if( go1->getAnimation() != NULL) 
    {
		go1BB =((IrrAnimatedMesh *)go1->getAnimation())->node->getTransformedBoundingBox();
	}
	if( go1->getMesh() != NULL ) 
    {
		go1BB = ((IrrMesh*)go1->getMesh())->node->getTransformedBoundingBox();
	}
		

	if( go2->getAnimation() != NULL)
    {
		go2BB=((IrrAnimatedMesh *)go2->getAnimation())->node->getTransformedBoundingBox();
	}
	if( go2->getMesh() != NULL )
    {
		go2BB = ((IrrMesh*)go2->getMesh())->node->getTransformedBoundingBox();
	}

	return go1BB.intersectsWithBox( go2BB );
}
*/