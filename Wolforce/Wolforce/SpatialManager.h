#ifndef SPATIAL_MANAGER_H
#define SPATIAL_MANAGER_H

#include <list>
#include "dllDefine.h"
#include "Vector.h"
#include "GameObject.h"

using namespace std;

namespace WolfEngine{

class WOLFORCE_API SpatialManager{
public:
	 void setup(int scenewidth, int sceneheight, int cellsize);
	 void update();
	 void addObject(GameObject *obj);
	 void removeObject(GameObject *obj);
	 
private:
	int cols,rows;
	int sceneWidth,sceneHeight,cellSize;
	map<int,list<GameObject*>> *buckets;
	list<GameObject*> *colliders;

	void registerObject(GameObject *obj);
	void clear();
	list<int> getIdForObj(GameObject *obj);
	void addBucket(Vector vector,float width,list<int> *buckettoaddto);
	list<GameObject*> getNearby(GameObject *obj);
};
}
#endif
