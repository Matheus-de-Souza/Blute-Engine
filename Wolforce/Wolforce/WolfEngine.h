/*
    WolfForce Engine Project - 3D Game Engine Project
    Copyright (C) 2011  João Ricardo Bittencourt <joaorb@unisinos.br>

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
      Bairro Cristo Rei - São Leopoldo - RS
      CEP: 93022-000

      E-mail: jogos@unisinos.br
      Web-site: http://www.unisinos.br/jogos
*/

#ifndef ENGINE_H
#define ENGINE_H
#include "dllDefine.h"

#include "Scene.h"
#include "Camera.h"
#include "GameObject.h"
#include "Input.h"
#include "Behavior.h"
#include "GUIEnvironment.h"
#include "Level.h"
#include "CollisionManager.h"
#include "ScriptMachine.h"

namespace WolfEngine{
	class WOLFORCE_API EngineStrategy{
	public:
		virtual int init() = 0;
		virtual void loop(Scene*, GUIEnvironment *, CollisionManager *) = 0;
		virtual Scene *createScene() = 0;
		virtual void setMousePosition(int,int) = 0;
		
		virtual GUIEnvironment *getGUIEnvironment() = 0;
		virtual ScriptMachine *getScriptMachine() = 0;
		virtual Level *getLevel() = 0;
		virtual CollisionManager *getCollisionManager() = 0;
		virtual void addFileArchive(char *c) = 0;

		//ENCAPSULAR?
		//MOUSE
		virtual void setMousePosition(Vector) = 0;
		virtual void setRelativeMousePosition(Vector) = 0;
		virtual Vector getRelativeMousePosition() = 0;
		virtual Vector getMousePosition() = 0;
		virtual void setMouseVisible(bool) = 0;
		virtual bool isVisible() = 0;
		//OUTROS
		virtual void setWindowName(wchar_t *name) = 0;
		virtual void setFog(float start, float end, float density, bool perPixel)=0;
		virtual void setClearColor(unsigned int a, unsigned int r, unsigned int g, unsigned int b) = 0;

	};

	class WOLFORCE_API Engine{
	private:
		static Engine *instance;
		
		EngineStrategy *strategy;		
		Scene *currentScene;
		GUIEnvironment *currentGUI;
		Level *currentLevel;
		CollisionManager *currentCollisionManager;
		ScriptMachine *currentScriptMachine;
		Engine();		
		
	public:
		static Engine *GetInstance();

		Scene *createScene();
		void setCurrentScene(Scene *s);
		void setCurrentGUI(GUIEnvironment *ge);
		void setCurrentLevel(Level *lev);
		void setCurrentCollisionManager(CollisionManager *cm);
		void setScriptMachine(ScriptMachine *sm);
		void loop();
		void setMousePosition(int,int);
		void addFileArchive(char *c);

		GUIEnvironment *getGUIEnvironment();
		Level *getLevel();
		CollisionManager *getCollisionManager();
		ScriptMachine *getScriptMachine();

		void setMousePosition(Vector);
		void setRelativeMousePosition(Vector);
		Vector getRelativeMousePosition();
		Vector getMousePosition();
		void setMouseVisible(bool);
		bool isVisible();
		void setClearColor(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
		void setFog(float start, float end, float density, bool perPixel);
		void setWindowName(wchar_t *name);
	};

	class WOLFORCE_API EngineFactory{
	public:
		virtual EngineStrategy *createEngineStrategy() = 0;
		virtual GameObjectImpl *createGameObjectImpl(GameObject *o) = 0;
		virtual InputReceiver *createInputReceiver() = 0;

		static EngineFactory *getInstance() {return instance;}
		static void setFactory(EngineFactory *f) {
			instance = f;
			Input::setReceiver(instance->createInputReceiver());
		}
	private:
		static EngineFactory *instance;
	};	
}
#endif