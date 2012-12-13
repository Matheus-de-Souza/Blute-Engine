/*
NONO TUTORIAL
http://irrlicht.sourceforge.net/docu/example008.html
*/

#include <irrlicht.h>
#include <iostream>

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

int main()
{
	f32 incrementarotacao = 1;
	//Criar o dispositivo
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, dimension2d<u32>(640, 480), 16, false);	
	if (device == 0) return 1; 
	
	//Pegar o driver de video
	IVideoDriver* driver = device->getVideoDriver();
	//Pegar o gerenciador de cena
	ISceneManager* smgr = device->getSceneManager();
	
	
	//Pega uma sala modelada no 3D Studio
	
	//scene::IAnimatedMesh* mesh = smgr->getMesh("../../media/room.3ds");

	//Melhorar a qualidade da textura dos modelos feitos no 3DS

	//smgr->getMeshManipulator()->makePlanarTextureMapping(mesh->getMesh(0), 0.004f);
	
	//Cria um novo nodo

	/*ISceneNode* node = 0;
	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setMaterialTexture(0, driver->getTexture("../../media/wall.jpg"));
	node->getMaterial(0).SpecularColor.set(0,0,0,0);*/
	
	//AGUA ANIMADA
	//Cria um plano para terreno. Tem um nome, número de celulas (linhas e colunas)
	//o tamanho de cada tile, material, altura, número de elevações, repetiação da textura
	
	/*mesh = smgr->addHillPlaneMesh("myHill",
                dimension2d<f32>(20,20),
                dimension2d<u32>(40,40), 0, 0,
                dimension2d<f32>(0,0),
                dimension2d<f32>(10,10));*/
	
	//Pega a estrutura e adiciona como agua
	//além do mesh especifica a altura, velocidade e tamanho das ondas

	//node = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);

	//posiciona o nodo

	//node->setPosition(vector3df(0,7,0));
	
	//Adiciona texturas de chao e de agua

	/*node->setMaterialTexture(0, driver->getTexture("../../media/stones.jpg"));
	node->setMaterialTexture(1, driver->getTexture("../../media/water.jpg"));*/

	//Cria o efeito de reflexao da textura 1 na textura 0

	//node->setMaterialType(EMT_REFLECTION_2_LAYER);

	//LUZ DINAMICA + BILLBOARD
	//Adiciona fonte de luz
	
	//node = smgr->addLightSceneNode(0, vector3df(0,0,0),SColorf(1.0f, 0.6f, 0.7f, 1.0f), 800.0f);
	//ISceneNodeAnimator* anim = 0;

	//Animação circular

	/*anim = smgr->createFlyCircleAnimator (vector3df(0,150,0),250.0f);
	node->addAnimator(anim);
	anim->drop();*/
	
	//Coloca um billoboard na luz

	//node = smgr->addBillboardSceneNode(node, dimension2d<f32>(50, 50));
	//node->setMaterialFlag(video::EMF_LIGHTING, false);
	//node->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	//node->setMaterialTexture(0, driver->getTexture("../../media/portal1.bmp"));



	//SISTEMA DE PARTÍCULAS
	//cria um sistema de particula sem o emissor padrao (uso do false)
	IParticleSystemSceneNode* ps = smgr->addParticleSystemSceneNode(false);
	
	//Cria um novo emissor na forma de caixa
	IParticleEmitter* em = ps->createRingEmitter(
				vector3df(0,0,0),
				f32(5.0), f32(1.0),          //a caixa com determinado tamanho
                vector3df(0.0f,0.0f,0.0f),   //direção inicia
                80,5000,                       //taxa de emissao- particulas/segundo min e max
                SColor(0,200,200,200),        //Cor mais escura
                SColor(0,200,100,200),       //Cor mais brilhante
                1500,2000,0,                   //tempo de vida minimo, máximo e angulo da particula
                dimension2df(0.02f,0.02f),     //tamanho minimo da particula
                dimension2df(2.f,2.f));    //tamanho maximo da particula
	
	//Defini o emissor no sistema de particulas
	ps->setEmitter(em);
	em->drop(); //elimina o emissor
	
	//Afetuador de fade out nas particulas
	//IParticleAffector* paf = ps->createFadeOutParticleAffector();
	IParticleAffector* pof = ps->createAttractionAffector(vector3df(0,0,50), f32(5.0f), true, true, true, true );
	
	IParticleAffector* pif = ps->createRotationAffector(vector3df(0.0f,100.0f,-50.0f), vector3df(0,0,50));

	ps->setRotation(vector3df(39.0, 20.0, 0.0));


	//Atribui o afetuador
	//ps->addAffector(paf);
	ps->addAffector(pof);
	ps->addAffector(pif);

	//paf->drop();
	pof->drop();
	pif->drop();
	
	//Posiciona o sistema de particulas
	ps->setPosition(core::vector3df(0,0,50));		//posição da particula fogo
	ps->setScale(core::vector3df(2,2,2));
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	
	//Atribui uma textura para a particula
	ps->setMaterialTexture(0, driver->getTexture("../../media/portal1.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);

	//LUZ VOLUMETRICA - EFEITO DE NEBLINA
	//Sem nodo pai, sem ID
	IVolumeLightSceneNode * n = smgr->addVolumeLightSceneNode(0, -1,
                                32,                              // Subdivisões em U
                                32,                              // Subdivisões em V
                                SColor(0, 255, 255, 255), // Cor inicial/base
                                SColor(0, 0, 0, 0));      // Cor final
	//Se criou
	if (n){
		//posiciona
		n->setScale(vector3df(56.0f, 56.0f, 56.0f));    //scala da luz roxa
		n->setPosition(vector3df(-120,50,40));			//posição da luz roxa
		
		//Carrega texturas para animação
		array<video::ITexture*> textures;
		for (s32 g=7; g > 0; --g)
		{
			stringc tmp;
			tmp = "../../media/portal";
			tmp += g;
			tmp += ".bmp";
			ITexture* t = driver->getTexture(tmp.c_str());
			textures.push_back(t);
		}
		
		// Cria um animador de textura
		ISceneNodeAnimator* glow = smgr->createTextureAnimator(textures, 150);
		// Adiciona no nodo
		n->addAnimator(glow);
		glow->drop();
	}

	//SOMBRA (DINÂMICA)
	//Carrega o mesh do anão
	
	//mesh = smgr->getMesh("../../media/dwarf.x");
	//IAnimatedMeshSceneNode* anode = 0;
	
	//anode = smgr->addAnimatedMeshSceneNode(mesh);
	/*anode->setPosition(vector3df(-50,20,-60));
	anode->setAnimationSpeed(15);*/
	
	//Define que terá sombra e com tal cor

	/*anode->addShadowVolumeSceneNode();	
	smgr->setShadowColor(SColor(150,0,0,0));*/
	
	//Escala e normaliza as normais
	
	/*anode->setScale(core::vector3df(2,2,2));
	anode->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);*/
	
	//Adiciona camera
	ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS();
	camera->setPosition(vector3df(0,0,0));
	
	//Desabilita o cursor
	device->getCursorControl()->setVisible(false);
	
	s32 lastFPS = -1;
	//Game lopp
	while(device->run()){
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, 0);
			smgr->drawAll();
			driver->endScene();

			
			const s32 fps = driver->getFPS();
			if (lastFPS != fps)
			{
				core::stringw str = L"Irrlicht Engine - SpecialFX example [";
				str += driver->getName();
				str += "] FPS:";
				str += fps;
				
				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
		}
	}
	device->drop();
	return 0;
}