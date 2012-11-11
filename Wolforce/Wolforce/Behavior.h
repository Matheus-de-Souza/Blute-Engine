/*
    WolfForce Engine Project - 3D Game Engine Project
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

#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include "dllDefine.h"

#include "StateMachine.h"
#include <list>

/*! \file Behavior.h
	\brief Cabe�alho com a defini��o da classe Behavior

	Defini��o da classe de comportamentos
*/

namespace WolfEngine{
	//!Representa um comportamento gen�rico
    /*!
    Classe utilizada para definir diferentes tipos de comportamentos.
    */
	class WOLFORCE_API Behavior{
	public:
		//!Executa o comportamento definido no m�todo
        /*!
        Executa o comportamento definido no m�todo. Classes devem ser derivadas
		desta classe base para criar o comportamento.
        */
		virtual void update() = 0;
		//!Define um game object ao comportamento
        /*!
        Associa um game object ao comportamento
		\param o � um game object
        */
		void setGameObject(GameObject *o) {gameObject=o;}
	protected:
		GameObject *gameObject;				//!<O objeto que o comportamento est� relacionado
	};

	class WOLFORCE_API FSMBehavior: public Behavior{
	private:
		StateMachine *fsm;	
		list<Action*> *acts;
	public: 
		FSMBehavior(StateMachine *f) {
			fsm = f;
			acts = new list<Action *>();
		}
		void update()
		{
			acts = fsm->update(acts);
			list<Action *>::iterator i;
			for(i=acts->begin(); i!=acts->end(); i++)
			{
				(*i)->exec();
			}
		}
	};
}
#endif