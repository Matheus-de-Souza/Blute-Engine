

#include "irrlicht.h"
#include "Particles.h"

using namespace WolfEngine;
using namespace irr;
using namespace scene;
#include "dllIrrDefine.h"
namespace IrrWolforce{
	class IRRWOLFORCE_API IrrParticles : public Particles
	{
	public:
		IrrParticles(IParticleSystemSceneNode *ps);
		~IrrParticles(void);
		void createBoxEmiter();
		void createPointEmitter();

		void setEnable(bool isEnable);
		void setVisible(bool isVisible);

		IParticleSystemSceneNode* node;
		IParticleEmitter* emitter;
	};

}