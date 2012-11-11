#include <string.h>
#include "irrlicht.h"

#include "Sphere.h"

using namespace WolfEngine;

using namespace irr;
using namespace scene;
#include "dllIrrDefine.h"
namespace IrrWolforce{
	class IRRWOLFORCE_API IrrSphere: public GameObject{
	private:
		IMeshSceneNode *node;

	public:
		IrrSphere(IMeshSceneNode *);
		void setPosition(float,float,float);
		void setName(std::string*);
		void setName(const char*s){setName(new std::string(s));}
	};
}