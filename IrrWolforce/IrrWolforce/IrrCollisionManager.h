#ifndef IRR_COLLISION_MANAGER_H
#define IRR_COLLISION_MANAGER_H

#include "irrlicht.h"

#include "CollisionManager.h"
#include "Behavior.h"
#include <vector>

#include <string>
#include <map>

using namespace WolfEngine;
using namespace std;

using namespace irr;
using namespace scene;
#include "dllIrrDefine.h"
namespace IrrWolforce
{
	class IRRWOLFORCE_API IrrCollisionManager :	public CollisionManager
	{

	public:
        IrrCollisionManager(IrrlichtDevice *d);

		void setCollider(GameObject *level, bool opt=false);
		void addResponse(GameObject *level, GameObject *target,  Vector radius, Vector offset);
		void createLevel(GameObject *target);
		void checkCollisions(std::vector<GameObject*> objects);
        /*void setSelectors();
        void setSelector(GameObject *);
        void addSelectorToGameObject(GameObject *);
        void addLevelSelector(Level *);
        void addLevelSelector(GameObject *);
        void addToMetaSelector(GameObject *, char *);
        void addMetaToGameObject(char *, GameObject *);
        virtual bool getCollisionFromBB(GameObject *go1, GameObject *go2);*/
        
    protected:
		IrrlichtDevice *device;
		scene::ISceneManager *smgr;

    private:
		//int gambs, gambs2;
        ITriangleSelector* selector;

        //scene::IMetaTriangleSelector *metaSelector;
		//std::map<char *, IMetaTriangleSelector *> *metaSelectors;
        //ISceneNode *levelMeshNodeX;
        //IMeshSceneNode *levelMeshNode;
    };
}

#endif