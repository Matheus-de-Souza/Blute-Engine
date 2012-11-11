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
#include "Scene.h"

using namespace WolfEngine;

Scene::Scene(){
	this->objects = new vector<GameObject*>();
	paused = false;
	sceneheight = 0;
	scenewidth = 0;
}

void Scene::addObject(GameObject *o){
	objects->push_back(o);
}

void Scene::update(){
	if(!paused) 
	{
	vector<GameObject*>::iterator i;	
		for(i=objects->begin(); i!=objects->end(); i++){
			if( (*i)->getImplementor()->isActive())
		(*i)->update();
			else 
			{
				delete (*i);
				(*i) = NULL;
				objects->erase(i);
			}
		}
	}
}


vector<GameObject*> Scene::getObjects()
{
	return *objects;
}

//Procura o objeto por ID e por nome
GameObject* Scene::findByNameAndId(std::string *nomeObjeto, int IDObjeto)
{
	GameObject *objeto = new GameObject();
	std::list<GameObject*> listaObjetos;
	vector<GameObject*>::iterator iteradorVetor;
	iteradorVetor = objects->begin();
	while(iteradorVetor!=objects->end())
	{
		if((*iteradorVetor)->getName()==nomeObjeto)
		{
			listaObjetos.push_back((*iteradorVetor));
		}
		iteradorVetor++;
	}
	std::list<GameObject*>::iterator iteradorLista;
	iteradorLista = listaObjetos.begin();
	while(iteradorLista != listaObjetos.end())
	{
		if(IDObjeto==(*iteradorLista)->getID())
		{
			objeto = (*iteradorLista);
		}
		iteradorLista ++;
	}

	return objeto;
}

bool Scene::isPaused()
{
	return paused;
}

void Scene::setPause(bool p)
{
	paused = p;
}