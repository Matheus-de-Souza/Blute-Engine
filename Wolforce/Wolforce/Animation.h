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

#ifndef ANIMATION_H
#define ANIMATION_H
#include "dllDefine.h"

/*! \file Animation.h
	\brief Cabeçalho com a definição das classes AnimationEntry e Animation.

	Arquivo contendo as definições das classes de animação e a descrição de cada uma das animações.
*/

#include <string>
#include <map>

#include "Component.h"
using namespace std;


namespace WolfEngine{
	//!Representa a definição de cada animação de um modelo animado
    /*!
    Classe responsável por definir as animações contidas em um modelo.
    */
	class WOLFORCE_API AnimationEntry{
	private:
		string *name;					//!< nome que identifica a animação
		int start;						//!< tempo inicial da animação
		int end;						//!< tempo final da animação
		int speed;						//!< velocidade da animação em frames por segundo

		bool loop;						//!< define se a animação está em loop

		int totalFrames;				//!< total de drames da animação

		bool interrupts;				//!< define se a animação pode interromper outras animações
		bool interruptable;				//!< define se a animação pode ser interrompida por outras animações

		int precedence;

	public:
		//!Cria uma nova definição de uma animação
        /*!
        Cria a especificação de uma animação usando um
		identificador, tempo inicial, tempo final, velocidade 
		e se deve estar em loop
        \param n é o identificador da animação
		\param s é o tempo inicial da animação (frame)
		\param e é o tempo final da animação (frame)
		\param sp é a velocidade da aniamação expressa em frames por segundo. Default é 30 fps
		\param n é se a animação deve estar em loop. Default é false
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
		//!Retorna o identificador da animação
        /*!
        Informa o identificador da animação
        \return o nome dado para animação
        */
		string *getName() {return name;}
		//!Retorna o tempo inicial da animação
        /*!
        Informa o tempo inicial da animação
        \return o tempo inicial da animação
        */
		int getStartFrame(){return start;}
		//!Retorna o tempo final da animação
        /*!
        Informa o tempo final da animação
        \return o tempo final da animação
        */
		int getEndFrame(){return end;}
		//!Retorna a velocidade da animação
        /*!
        Informa a velocidade da animação
        \return a velocidade da animação
        */
		int getSpeed(){return speed;}
		//!Verifica se a animação está em loop
        /*!
        Informa se a animação está em loop
        \return true se a animação está em loop, false caso contrário
        */
		int getTotalFrames(){return totalFrames;}

		bool getInterrupts(){return interrupts;}

		bool getInterruptable(){return interruptable;}

		int getPrecedence(){return precedence;}

		int isLoop() {return loop;}
	};

	//!Representa um componente de animação
    /*!
	Componente que contem a descrição de várias animações de um modelo animado
    */
	class WOLFORCE_API Animation: public Component{
	public:
		Animation();					//!<Construtor padrão
		//!Executa uma animação
        /*!
        Trata-se de uma promessa de método (virtual).
		Deve reproduzir uma animação associada ao componente
        \param n é o nome da animação para ser executada
        */
		virtual void play(char *n) = 0;
		void addAnimation(AnimationEntry *ae);
		//!Adiciona uma animação no componente
        /*!
        Adiciona uma nova animação no componente
        \param ae é a descrição de uma animação
        */

		AnimationEntry *ae;

		AnimationEntry *getAnimationEntry(char *p);

	protected:
		map<string,AnimationEntry *> *animations; //!<Mapa que relaciona nome => descrição da animação
	};
}
#endif