#ifndef IRR_SCENE_H
#define IRR_SCENE_H
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

#include "irrlicht.h"

#include "Scene.h"
#include "irrKlang.h"

using namespace WolfEngine;

using namespace irr;
using namespace scene;
using namespace irrklang;
using namespace video;
#include "dllIrrDefine.h"
namespace IrrWolforce{
	class IRRWOLFORCE_API IrrScene: public Scene{
	private:
		ISceneManager *smgr;
		ISoundEngine *soundEngine;
		IVideoDriver *driver;
		scene::ITriangleSelector* selector;

	public:
		//IrrScene(ISceneManager *,ISoundEngine *);
		IrrScene(ISceneManager *,ISoundEngine *, IVideoDriver *);
		GameObject *addCube(Vector*, bool = true);
		GameObject *addSphere(Vector*, bool = true);
		GameObject *addAnimatedMesh(char *,Vector*, bool = true);
		GameObject *addMesh(char *,Vector*, bool = true);
		GameObject *addCamera(Vector*,Vector*);
		GameObject *addAudio(const char *,int,Vector*);
		GameObject *addParticles(char *imageFileName);
		GameObject *addOctree(char *file);

		//meus metodos
		void loadScene(char *);					// carrega uma cena apartir de um arquivo .irr 
		int getNodeCount(char *);				// retorna quantos nodos com aquele nome existem, de ser passado o nome principal do nome, exemplo, "Enemy" e o programa vai procurar por "Enemy_1 e assim em diante 
		Vector *getNodePosition(char *);		// retorna um vetor contendo a posicao de todos os inimigos, em ordem numerica. A string passada como parametro segue a ideia do metodo acima.

		void createAutomaticCollision(GameObject *player, GameObject *cenario, Vector center);
	};
}
#endif