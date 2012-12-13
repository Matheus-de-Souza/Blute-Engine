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
#ifndef SCENE_H
#define SCENE_H
#include "dllDefine.h"
#include "GameObject.h"
#include "SpatialManager.h"
#include "Vector.h"
#include <vector>

using namespace std;

namespace WolfEngine{
	class WOLFORCE_API Scene{
	public:
		Scene();
		virtual GameObject *addCube(Vector*, bool = true)=0;
		virtual GameObject *addSphere(Vector*, bool = true)=0;
		virtual GameObject *addCamera(Vector*,Vector*)=0;
		virtual GameObject *addAnimatedMesh(char *,Vector*, bool = true)=0;
		virtual GameObject *addMesh(char *,Vector*, bool = true)=0;
		virtual GameObject *addAudio(const char *,int,Vector*)=0;
		virtual GameObject *addParticles(char *)=0;
		virtual GameObject *addOctree(char *)=0;
		
		//meus metodos
		virtual void loadScene(char *)=0;
		virtual int getNodeCount(char *)=0;
		virtual Vector *getNodePosition(char *)=0; //by name

		
		virtual void createAutomaticCollision(GameObject *player, GameObject *cenario, Vector c)=0;

		void update();
		bool isPaused();
		void setPause(bool p);

		vector<GameObject*> getObjects();
		GameObject* findByNameAndId(std::string *nomeObjeto, int IDObjeto);

	protected:
		void addObject(GameObject*);
		bool paused;

	private:
		vector<GameObject*> *objects;
		SpatialManager spatial;
		int scenewidth;
		int sceneheight;
	};
}
#endif