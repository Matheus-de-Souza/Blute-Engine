#include "IrrParticles.h"

using namespace IrrWolforce;
using namespace core;
using namespace std;

IrrParticles::IrrParticles(IParticleSystemSceneNode *ps)
{
	this->node = ps;
	this->node->setEmitter(NULL);
	this->node->setVisible(true);


	scene::IParticleEmitter* em = this->node->createBoxEmitter(
			core::aabbox3d<f32>(-1000,0,-1000,1000,1,1000), // emitter size
			core::vector3df(0.0f,-0.35f,0.0f),   // initial direction
			300,400,                             // emit rate
			video::SColor(0,127,127,127),       // darkest color
			video::SColor(0,255,255,255),       // brightest color
			1800,1800,10,                         // min and max age, angle
			core::dimension2df(10.f,10.f),         // min size
			core::dimension2df(20.f,20.f));        // max size

	emitter = em;
	((scene::IParticleSystemSceneNode*)ps)->setEmitter(emitter); 
	scene::IParticleAffector* paf1 = ps->createFadeOutParticleAffector();
	ps->addAffector(paf1); // same goes for the affector
	paf1->drop();

	this->node->setPosition(core::vector3df(0,500,0));
	this->node->setScale(core::vector3df(1,1,1));
	this->node->setMaterialFlag(video::EMF_LIGHTING, false);
	this->node->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	this->node->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);




}


IrrParticles::~IrrParticles(void)
{
}

void IrrParticles::createBoxEmiter()
{

}

void IrrParticles::createPointEmitter()
{

}

void IrrParticles::setEnable(bool isEnable)
{

	if(isEnable == true) {
		if(this->emitter) 
			this->node->setEmitter(this->emitter);
	}
	else 
		this->node->setEmitter(NULL);
	
}

void IrrParticles::setVisible(bool isVisible)
{
	this->node->setVisible(isVisible);
}