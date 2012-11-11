#include "IrrLevel.h"

using namespace IrrWolforce;

IrrLevel::IrrLevel(void)
{
}


IrrLevel::~IrrLevel(void)
{
}

IrrLevel::IrrLevel(IrrlichtDevice *d)
{
	levelMeshNode = NULL;
	this->device = d;
}

void IrrLevel::load(char *p)
{
	scene::ISceneManager* smgr = device->getSceneManager();

	device->getFileSystem()->addZipFileArchive(p);

	scene::IAnimatedMesh* q3levelmesh = smgr->getMesh("20kdm2.bsp");

	if (q3levelmesh)
	{
		levelMeshNode = smgr->addOctreeSceneNode(q3levelmesh->getMesh(0), 0);
		levelMeshNode->setPosition(core::vector3df(-1350,-130,-1400));
		printf("funfooooooooooooooooou \n");
	}
}

IMeshSceneNode *IrrLevel::getThisMesh()
{
	return levelMeshNode;
}