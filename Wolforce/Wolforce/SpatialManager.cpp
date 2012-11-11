#include "SpatialManager.h"
#include <algorithm>

using namespace WolfEngine;
/*
http://conkerjo.wordpress.com/2009/06/13/spatial-hashing-implementation-for-fast-2d-collisions/
*/
void SpatialManager::setup(int scenewidth, int sceneheight, int cellsize){
	cols= scenewidth / cellsize;
    rows= sceneheight / cellsize;
    buckets = new map<int,list<GameObject*>>();

    for (int i = 0;i<cols*rows;i++){
		buckets->insert(pair<int,list<GameObject*>>(i,list<GameObject*>()));
    }

    sceneWidth = scenewidth;
    sceneHeight = sceneheight;
    cellSize = cellsize;
	colliders = new list<GameObject*>();
}

void SpatialManager::update(){
	clear();
	//registra os objetos
	list<GameObject*>::iterator it = colliders->begin();
	for(it; it!=colliders->end(); it++){
		registerObject(*it);
	}	
	it = colliders->begin();
	//checa colisao
	for(it; it!=colliders->end(); it++){
		list<GameObject*> near = getNearby(*it);		
		if(near.size()!=0){
			list<GameObject*>::iterator nit = near.begin();
			for(nit; nit!=near.end(); nit++){
				if((*it)->collide(*nit)){
					//trata a colisao
				}
			}			
		}
	}	
}

void SpatialManager::addObject(GameObject *obj){
	colliders->push_back(obj);
}

void SpatialManager::removeObject(GameObject *obj){
	list<GameObject*>::iterator result;
	result = find(colliders->begin(), colliders->end(),obj);
	if(result!=colliders->end()){
		colliders->erase(result);
	}
}

void SpatialManager::registerObject(GameObject *obj){
	list<int> cellIds= getIdForObj(obj);
	list<int>::iterator it = cellIds.begin();
	for(it; it!=cellIds.end(); it++){
		buckets->find(*it)->second.push_back(obj);
	}
}
	 
void SpatialManager::clear(){
	buckets->clear();
    for (int i = 0; i < cols * rows; i++){
		buckets->insert(pair<int,list<GameObject*>>(i,list<GameObject*>())); 
	}
}

list<int> SpatialManager::getIdForObj(GameObject *obj){
	list<int> *bucketsObjIsIn = new list<int>();
           
		Vector pos;
		Vector rad;
		obj->getPosition(pos);
		obj->getRadius(rad);

        Vector *min = new Vector(
			pos.x - (rad.x),
			pos.y - (rad.y),
			0.0);   
        Vector *max = new Vector(
            pos.x + (rad.x),
            pos.y + (rad.y),
			0.0);

        float width = sceneWidth/cellSize;   
        //TopLeft
        addBucket(*min,width,bucketsObjIsIn);
        //TopRight
        addBucket(Vector(max->x, min->y), width, bucketsObjIsIn);
        //BottomRight
        addBucket(Vector(max->x, max->y), width, bucketsObjIsIn);
        //BottomLeft
        addBucket(Vector(min->x, max->y), width, bucketsObjIsIn);

	return *bucketsObjIsIn; 
}

void SpatialManager::addBucket(Vector vector,float width,list<int> *buckettoaddto){
	int cellPosition = (int)(
                   (floor(vector.x/cellSize)) +
                   (floor(vector.y/cellSize)) *
                   width);
	list <int>::iterator result;
	result = find(buckettoaddto->begin(),buckettoaddto->end(),cellPosition);
	if (result == buckettoaddto->end( )){
		buckettoaddto->push_back(cellPosition);
	}
}

list<GameObject*> SpatialManager::getNearby(GameObject *obj){
	list<GameObject*> *objects = new list<GameObject*>();
    list<int> bucketIds = getIdForObj(obj);
	list<int>::iterator it = bucketIds.begin();
	for(it; it!=bucketIds.end(); it++){
		list<GameObject*> tmp = buckets->find(*it)->second;
		list<GameObject*>::iterator itmp = tmp.begin();
		for(itmp; itmp!=tmp.end(); itmp++){
			objects->push_back(*itmp);
		}
	}
	return *objects;  
}