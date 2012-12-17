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
#include "WolfEngine.h"

using namespace WolfEngine;

Engine *Engine::instance = 0;

EngineFactory *EngineFactory::instance = 0;

Engine::Engine(){
	strategy = EngineFactory::getInstance()->createEngineStrategy();
	if(strategy->init()){
		//deu erro
	}

	this->currentScene = NULL;
	this->currentGUI = NULL;
	this->currentLevel = NULL;
	
	this->currentCollisionManager = NULL;
	this->currentCollisionManager = getCollisionManager();;
}

Engine *Engine::GetInstance()
{
	if(Engine::instance==NULL){
		Engine::instance = new Engine;
	}
	return Engine::instance;
}

void Engine::setCurrentScene(Scene *s)
{
	this->currentScene = s;
}

void Engine::setCurrentGUI(GUIEnvironment *g)
{
	this->currentGUI = g;
}

void Engine::setCurrentLevel(Level *l)
{
	this->currentLevel = l;
}

void Engine::setCurrentCollisionManager(CollisionManager *cm)
{
	this->currentCollisionManager = cm;
}

void Engine::setScriptMachine(ScriptMachine *sm)
{
	this->currentScriptMachine =sm;
}

void Engine::loop()
{
	Engine::strategy->loop(this->currentScene, this->currentGUI, this->currentCollisionManager);
}

void Engine::setMousePosition(int x, int y)
{
	Engine::strategy->setMousePosition(x,y);
}


Scene *Engine::createScene(){
	Scene *s = Engine::strategy->createScene();
	setCurrentScene(s);
	return s;
}

GUIEnvironment *Engine::getGUIEnvironment()
{
	GUIEnvironment *ge = Engine::strategy->getGUIEnvironment();
	setCurrentGUI(ge);
	return ge;
}

ScriptMachine *Engine::getScriptMachine()
{
	ScriptMachine *sm = Engine::strategy->getScriptMachine();
	setScriptMachine(sm);
	return sm;
}

Level *Engine::getLevel()
{
	Level *lev = Engine::strategy->getLevel();
	setCurrentLevel(lev);
	return lev;
}



void Engine::setMousePosition(Vector pos)
{
	Engine::strategy->setMousePosition(pos);
}

void Engine::setRelativeMousePosition(Vector pos)
{
	Engine::strategy->setRelativeMousePosition(pos);
}

Vector Engine::getRelativeMousePosition()
{
	return Engine::strategy-> getRelativeMousePosition();
}

Vector Engine::getMousePosition()
{
	return Engine::strategy->getMousePosition();
}

void Engine::setMouseVisible(bool visible)
{
	Engine::strategy->setMouseVisible(visible);
}

bool Engine::isVisible()
{
	return Engine::strategy->isVisible();
}

void Engine::setClearColor(unsigned int a, unsigned int r, unsigned int g, unsigned int b)
{
	Engine::strategy->setClearColor(a,r,g,b);
}

void Engine::setFog(float start, float end, float density, bool perPixel)
{
	Engine::strategy->setFog(start,end,density,perPixel);
}

void Engine::setWindowName(wchar_t *name)
{
	Engine::strategy->setWindowName(name);
}

CollisionManager *Engine::getCollisionManager()
{
	if(currentCollisionManager == NULL)
    {
        this->setCurrentCollisionManager(Engine::strategy->getCollisionManager());
    }

	return currentCollisionManager;
}

void Engine::addFileArchive(char *c){
	Engine::strategy->addFileArchive(c);
}

void Engine::closeApplication()
{
	Engine::strategy->closeApplication();
}