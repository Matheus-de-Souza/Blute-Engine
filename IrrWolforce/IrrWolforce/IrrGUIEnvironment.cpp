#include "IrrGUIEnvironment.h"

using namespace IrrWolforce;
#include <iostream>


IrrGUIEnvironment::IrrGUIEnvironment(void)
{
}


IrrGUIEnvironment::~IrrGUIEnvironment(void)
{
}

IrrGUIEnvironment::IrrGUIEnvironment(IGUIEnvironment *ge)
{
	this->guiTextures = new map<std::string, ITexture *>();
	this->guiImages = new map<std::string, IGUIImage *>();

	this->guiEnv = ge;
}

IrrGUIEnvironment::IrrGUIEnvironment(IGUIEnvironment *ge, IVideoDriver *vd)
{
	this->guiTextures = new map<std::string, ITexture *>();
	this->guiImages = new map<std::string, IGUIImage *>();

	this->guiEnv = ge;
	this->driver = vd;
}

void IrrGUIEnvironment::loadImage(std::string name, char *p)
{
	ITexture *iTex;	 
	iTex = driver->getTexture(p);

	guiTextures->insert(std::pair<string, ITexture *>(name, iTex));

}


void IrrGUIEnvironment::addImage(std::string texName, std::string imgName, int x, int y)
{	
	ITexture *iTex;
	iTex = guiTextures->find(texName)->second;

	IGUIImage *guiImg;
	guiImg = guiEnv->addImage(iTex, core::vector2d<s32>(x, y));	

	guiImages->insert(std::pair<string, IGUIImage *>(imgName, guiImg));
}

void IrrGUIEnvironment::makeVisible(std::string n)
{
	IGUIImage *guiImg = guiImages->find(n)->second;
	guiImg->setVisible(true);

}

void IrrGUIEnvironment::makeInvisible(std::string n)
{
	IGUIImage *guiImg = guiImages->find(n)->second;
	guiImg->setVisible(false);
}

void IrrGUIEnvironment::update()
{

}

