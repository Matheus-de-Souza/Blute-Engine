#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "dllDefine.h"
#include "Level.h"
#include "GameObject.h"

namespace WolfEngine{

	class WOLFORCE_API CollisionManager
	{
	public:
		virtual void setCollider(GameObject *level, bool opt=false) = 0;
		virtual void addResponse(GameObject *level, GameObject *target, Vector radius, Vector offset) = 0;
		virtual void createLevel(GameObject *target) = 0;
		virtual void checkCollisions(std::vector<GameObject*> & objects) = 0;
		
		/*virtual void setSelectors() = 0;
        virtual void setSelector(GameObject *) = 0;
        virtual void addSelectorToGameObject(GameObject *) = 0;
		virtual void addLevelSelector(Level *) = 0;
        virtual void addLevelSelector(GameObject *) = 0;
        virtual void addToMetaSelector(GameObject *, char *) = 0;
        virtual void addMetaToGameObject(char *, GameObject *) = 0;
        virtual bool getCollisionFromBB(GameObject *go1, GameObject *go2) = 0;*/
	};
}

#endif


//class CollisionManager
//	{
//	public:
//		CollisionManager(void);
//		~CollisionManager(void);
//
//		/*virtual void setPlayerMeshNode(GameObject *go) = 0;
//
//		virtual void setEnemyMeshNode(GameObject *go) = 0;
//		
//		virtual void obtainLevelMesh(Level *l) = 0;*/
//
//		virtual void setSelectors() = 0;
//
//		/*virtual void addAnimatedMeshNode(GameObject *go) = 0;
//
//		virtual void update() = 0;
//
//        virtual bool getCollisionFromBB(GameObject *go1, GameObject *go2) = 0;*/
//
//	};