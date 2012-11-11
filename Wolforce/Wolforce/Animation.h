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

#ifndef ANIMATION_H
#define ANIMATION_H
#include "dllDefine.h"

/*! \file Animation.h
	\brief Cabe�alho com a defini��o das classes AnimationEntry e Animation.

	Arquivo contendo as defini��es das classes de anima��o e a descri��o de cada uma das anima��es.
*/

#include <string>
#include <map>

#include "Component.h"
using namespace std;


namespace WolfEngine{
	//!Representa a defini��o de cada anima��o de um modelo animado
    /*!
    Classe respons�vel por definir as anima��es contidas em um modelo.
    */
	class WOLFORCE_API AnimationEntry{
	private:
		string *name;					//!< nome que identifica a anima��o
		int start;						//!< tempo inicial da anima��o
		int end;						//!< tempo final da anima��o
		int speed;						//!< velocidade da anima��o em frames por segundo

		bool loop;						//!< define se a anima��o est� em loop

		int totalFrames;				//!< total de drames da anima��o

		bool interrupts;				//!< define se a anima��o pode interromper outras anima��es
		bool interruptable;				//!< define se a anima��o pode ser interrompida por outras anima��es

		int precedence;

	public:
		//!Cria uma nova defini��o de uma anima��o
        /*!
        Cria a especifica��o de uma anima��o usando um
		identificador, tempo inicial, tempo final, velocidade 
		e se deve estar em loop
        \param n � o identificador da anima��o
		\param s � o tempo inicial da anima��o (frame)
		\param e � o tempo final da anima��o (frame)
		\param sp � a velocidade da aniama��o expressa em frames por segundo. Default � 30 fps
		\param n � se a anima��o deve estar em loop. Default � false
        */
		AnimationEntry(char *n, int s,int e,int sp=30,bool lo=false, int pre = 0, bool i = false, bool ia = true){
			name = new string(n);
			start = s;
			end = e;
			loop = lo;
			speed = sp;

			interrupts = i;
			interruptable = ia;

			precedence = pre;

			totalFrames = end - start;
		}
		//!Retorna o identificador da anima��o
        /*!
        Informa o identificador da anima��o
        \return o nome dado para anima��o
        */
		string *getName() {return name;}
		//!Retorna o tempo inicial da anima��o
        /*!
        Informa o tempo inicial da anima��o
        \return o tempo inicial da anima��o
        */
		int getStartFrame(){return start;}
		//!Retorna o tempo final da anima��o
        /*!
        Informa o tempo final da anima��o
        \return o tempo final da anima��o
        */
		int getEndFrame(){return end;}
		//!Retorna a velocidade da anima��o
        /*!
        Informa a velocidade da anima��o
        \return a velocidade da anima��o
        */
		int getSpeed(){return speed;}
		//!Verifica se a anima��o est� em loop
        /*!
        Informa se a anima��o est� em loop
        \return true se a anima��o est� em loop, false caso contr�rio
        */
		int getTotalFrames(){return totalFrames;}

		bool getInterrupts(){return interrupts;}

		bool getInterruptable(){return interruptable;}

		int getPrecedence(){return precedence;}

		int isLoop() {return loop;}
	};

	//!Representa um componente de anima��o
    /*!
	Componente que contem a descri��o de v�rias anima��es de um modelo animado
    */
	class WOLFORCE_API Animation: public Component{
	public:
		Animation();					//!<Construtor padr�o
		//!Executa uma anima��o
        /*!
        Trata-se de uma promessa de m�todo (virtual).
		Deve reproduzir uma anima��o associada ao componente
        \param n � o nome da anima��o para ser executada
        */
		virtual void play(char *n) = 0;
		void addAnimation(AnimationEntry *ae);
		//!Adiciona uma anima��o no componente
        /*!
        Adiciona uma nova anima��o no componente
        \param ae � a descri��o de uma anima��o
        */

		AnimationEntry *ae;

		AnimationEntry *getAnimationEntry(char *p);

	protected:
		map<string,AnimationEntry *> *animations; //!<Mapa que relaciona nome => descri��o da anima��o
	};
}
#endif