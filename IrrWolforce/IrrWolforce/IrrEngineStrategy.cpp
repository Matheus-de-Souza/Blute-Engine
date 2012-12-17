/*
    WolfForce Engine Project - 3D Game Engine Project
	IrrWolforce - Irrlicht eXtension for WolfForce Engine Project
    Copyright (C) 2011  Jo�o Ricardo Bittencourt <joaorb@unisinos.br>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    For the purposes of the WolfForce Engine Project software we request that 
	software using or linking this engine or its libraries display the
    following notice:                                                            
                                                                                
              Created with WolfForce Engine Project
        http://code.google.com/p/wolfengine-project/
                                                                                
    Please see the software license located at license.txt
    for more details.                                                            
                                                                                
    You should have received a copy of the License along with this software;     
    if not, write to                                                             
                                                                                
      UNISINOS
      Av. Unisinos, 950
      Bairro Cristo Rei - S�o Leopoldo - RS
      CEP: 93022-000

      E-mail: jogos@unisinos.br
      Web-site: http://www.unisinos.br/jogos
*/

#include <windows.h>

#include "IrrEngineStrategy.h"

#include "IrrScene.h"
#include "IrrGameObjectImpl.h"
#include "IrrGUIEnvironment.h"
#include "IrrScene.h"
#include "IrrGameObjectImpl.h"
#include "IrrLevel.h"
#include "IrrCollisionManager.h"
#include "LuaVirtualMachine.h"

#include <IGUIWindow.h>

using namespace IrrWolforce;

#include "LuaVirtualMachine.h"
int IrrEngineStrategy::init()
{
	
	#ifdef _IRR_WINDOWS_
	//Para n�o abrir a janela do DOS
	//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
	#endif

		//irrklang::ISoundEngine* soundEngine = irrklang::createIrrKlangDevice();
		soundEngine = createIrrKlangDevice();

		inputsReceiver = EngineFactory::getInstance()->createInputReceiver();

		//Cria um novo dispositivo
		//qual o driver - no caso esta usando via software mesmo
		//tamanho da janela - 640x480
		//deep color
		//fullscren?
		//usa stencil buffer?
		//se utiliza vsync
		//o endere�o objeto para receber os eventos. No caso o default � 0
		device = createDevice( video::EDT_DIRECT3D9, dimension2d<u32>(1024, 768), 16, false, false, false, (IrrInput*)inputsReceiver);
		//Se nao conseguiu retornar encerra a aplica��o
        if (!device) return 1;

		//Titulo na janela
		device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

		//Pegar o driver de video
		driver = device->getVideoDriver();

		smgr = device->getSceneManager();
		smgr->setAmbientLight(SColorf(1,1,1,1));

		//Pegar a GUI
		guiEnv = device->getGUIEnvironment();
		
		//Setar uma clear color padrao
		clearColor.set(0,0,255,255);

	/*LuaVirtualMachine lvm;
	try{
		lvm.loadFile("../media/config.lua");
		int v = lvm.getInt("teste");
		cout << "teste=" << v << endl;
		GameObject *go = lvm.getGameObject("go");
		cout << "nome do go=" << *(go->getName()) << endl;
	}
	catch(const runtime_error& e){
		std::cout << e.what() << endl;
	}*/
		

		return 0;
}


void IrrEngineStrategy::loop(Scene *scene, GUIEnvironment *ge, CollisionManager *collMan)
{

		// Qual foi a ultima fatia de tempo
		u32 then = device->getTimer()->getTime();
		int lastFPS = -1;

		//Game loop
		while(device->run()){	
			//Pega a fatia de tempo atual
			const u32 now = device->getTimer()->getTime();
			//Pega a variacao do tempo
			const f32 frameDeltaTime = (f32)(now - then) / 1000.f; //Tempo em segundos
			//Define o tempo passado com o atual
			then = now;

			if(collMan!=NULL) collMan->checkCollisions(scene->getObjects());
			
			//Atualiza a cena			
			if(scene!=NULL) scene->update();

			//Limpa a cena com uma cor
			driver->beginScene(true, true, clearColor);

			//Grafo de cena renderiza
			smgr->drawAll();

			//Gerenciador da GUI renderiza
			if(ge!=NULL) ge->update();
			if(guiEnv!=NULL) guiEnv->drawAll();

			//Exibe o resultado na tela
			driver->endScene();

			//Pega o FPS
			int fps = driver->getFPS();
			//Se mudou ...
			if (lastFPS != fps)
			{					
				lastFPS = fps;
			}
		}
		//Encerra. Deleta todos os objetos
        device->drop();
}

Scene *IrrEngineStrategy::createScene()
{
	return new IrrScene(smgr,soundEngine,driver);
}


GUIEnvironment *IrrEngineStrategy::getGUIEnvironment()
{
	return new IrrGUIEnvironment(guiEnv, driver);
}
Level *IrrEngineStrategy::getLevel()
{
	return new IrrLevel(device);
}

CollisionManager *IrrEngineStrategy::getCollisionManager()
{
	return new IrrCollisionManager(device);
}

void IrrEngineStrategy::setMousePosition(int x, int y)
{
	this->device->getCursorControl()->setPosition(x,y);
}

void IrrEngineStrategy::setMousePosition(Vector pos)
{
	this->device->getCursorControl()->setPosition(pos.x,pos.y);
}

void IrrEngineStrategy::setRelativeMousePosition(Vector pos)
{
	this->device->getCursorControl()->setPosition(pos.x,pos.y);
}

Vector IrrEngineStrategy:: getRelativeMousePosition()
{
	vector2d<irr::f32> pos = this->device->getCursorControl()->getRelativePosition();
	Vector mPos;
	mPos.x = pos.X;
	mPos.y = pos.Y;
	return mPos;
}

Vector IrrEngineStrategy:: getMousePosition()
{
	vector2d<irr::s32> pos = this->device->getCursorControl()->getPosition();
	Vector mPos;
	mPos.x = (float)pos.X;
	mPos.y = (float)pos.Y;
	return mPos;
}

void IrrEngineStrategy::setMouseVisible(bool visible)
{
	this->device->getCursorControl()->setVisible(visible);
}

bool IrrEngineStrategy::isVisible()
{
	return this->device->getCursorControl()->isVisible();
}

void IrrEngineStrategy::setClearColor(unsigned int a, unsigned int r, unsigned int g, unsigned int b)
{
	clearColor.set(a,r,g,b);
}

void IrrEngineStrategy::setFog(float start, float end, float density, bool perPixel)
{
	driver->setFog(clearColor,EFT_FOG_LINEAR,start,end,density,perPixel,false);
}

void IrrEngineStrategy::setWindowName(wchar_t *name)
{

	device->setWindowCaption(name);
}

ScriptMachine *IrrEngineStrategy::getScriptMachine(){
	return new LuaVirtualMachine();
}

void IrrEngineStrategy::addFileArchive(char *c){
	device->getFileSystem()->addFileArchive(c);
}

void IrrEngineStrategy::closeApplication(){
	device->closeDevice();
}
//FACTORY
IrrlichtFactory::IrrlichtFactory()
{
	this->receiver = NULL;
}

EngineStrategy *IrrlichtFactory::createEngineStrategy()
{
	return new IrrEngineStrategy();
}

GameObjectImpl *IrrlichtFactory::createGameObjectImpl(GameObject *o)
{
	return new IrrGameObjectImpl(o);
}

InputReceiver *IrrlichtFactory::createInputReceiver()
{
	if(receiver==NULL){
		receiver = new IrrInput();
	}
	return receiver;
}
