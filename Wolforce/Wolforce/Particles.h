#ifndef PARTICLES_H
#define PARTICLES_H
#include "dllDefine.h"

#include "Component.h"
using namespace std;

namespace WolfEngine{

	class WOLFORCE_API Particles : public  Component
	{
	public:

		virtual void createBoxEmiter()=0;
		virtual void createPointEmitter()=0;
		virtual void setEnable(bool isEnable)=0;
		virtual void setVisible(bool isVisible)=0;
	};

}

#endif