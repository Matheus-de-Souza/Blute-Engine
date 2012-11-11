#ifndef IRR_LEVEL_H
#define IRR_LEVEL_H

#include "irrlicht.h"

#include "Level.h"

using namespace WolfEngine;
using namespace std;

using namespace irr;
using namespace scene;

#include "dllIrrDefine.h"
namespace IrrWolforce
{
	class IRRWOLFORCE_API IrrLevel : public Level
	{
	public:
		IrrLevel(void);
		IrrLevel(IrrlichtDevice *d);
		~IrrLevel(void);

		void load(char *p);
		IMeshSceneNode *getThisMesh();

	private:
		IrrlichtDevice *device;
		IMeshSceneNode *levelMeshNode;
	};
}

#endif