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


#include "WolfEngine.h"

#include "irrlicht.h"
#include "irrKlang.h"

#include "IrrInput.h"

using namespace WolfEngine;

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace gui;

using namespace irrklang;
#include "dllIrrDefine.h"
namespace IrrWolforce{
	class IRRWOLFORCE_API IrrEngineStrategy: public EngineStrategy{
	private:
		IrrlichtDevice *device;
		IVideoDriver* driver;
		ISceneManager* smgr;
		IGUIEnvironment *guiEnv;
		InputReceiver* inputsReceiver;

		ISoundEngine* soundEngine;
		SColor clearColor;

	public:
		int init();
		void loop(Scene*, GUIEnvironment *, CollisionManager *);
		Scene *createScene();
		GUIEnvironment *getGUIEnvironment();
		Level *getLevel();
		CollisionManager *getCollisionManager();
		ScriptMachine *getScriptMachine();
		void addFileArchive(char *c);

		void setMousePosition(int,int);
		void setMousePosition(Vector);
		void setRelativeMousePosition(Vector);
		Vector getRelativeMousePosition();
		Vector getMousePosition();
		void setMouseVisible(bool);
		bool isVisible();
		void setClearColor(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
		void setFog(float start, float end, float density, bool perPixel);
		void setWindowName(wchar_t *name);
		void closeApplication();
	};

	class IRRWOLFORCE_API IrrlichtFactory: public EngineFactory{
	public:
		IrrlichtFactory();
		EngineStrategy *createEngineStrategy();
		GameObjectImpl *createGameObjectImpl(GameObject *o);
		InputReceiver *createInputReceiver();
	private:
		IrrInput *receiver;
	};
}