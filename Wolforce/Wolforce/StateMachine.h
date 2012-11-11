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

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "dllDefine.h"

/*! \file StateMachine.h
	\brief Cabeçalho com a definição da classe StateMachine

	Definição da classe de máquinas de estados
*/
#include <list>
#include <iostream>
using namespace std;

namespace WolfEngine{
	

	class WOLFORCE_API Action{
	public:
		virtual void exec() = 0;
	};

	class WOLFORCE_API Condition{
	public:
		virtual bool test() = 0;
	};

	class Transition;

	class WOLFORCE_API State{
		list<Transition*> *outgoing;
		list<Action*> *actions;
		Action *entryAction;
		Action *exitAction;

	public:
		State();				
		void addTransition(Transition *);
		void addAction(Action *a);

		list<Action*> *getAction() { return actions;}
		Action *getEntryAction() {return entryAction;}
		Action *getExitAction() {return exitAction;}
		list<Transition*> *getTransitions() {return outgoing;}
		void setEntryAction(Action *a) {entryAction = a;}
		void setExitAction(Action *a) {exitAction = a;}
	};

	class WOLFORCE_API Transition{
	private:
		Condition *condition;
		Action *action;
		State *toState;

	public:
		bool isTriggered();

		State *getTargetState() {return toState;}
		Action *getAction() {return action;}
		void setCondition(Condition *c) {condition = c;}
		void setAction(Action *a) {action = a;}
		void setTargetState(State *s) {toState = s;}
	};

	class WOLFORCE_API StateMachine{
	private:
		list<State*> *states;
		State *initialState, *currentState;

	public:
		StateMachine(State *);
		list<Action*> *update(list<Action*> *);
		void addState(State *);
	};

	class WOLFORCE_API NotCondition: public Condition{
	private:
		Condition *cond;
	public:
		NotCondition(Condition *c) { cond = c;};
		bool test(){
			return !cond->test();
		}
	};

	class WOLFORCE_API AndCondition: public Condition{
	private:
		Condition *cond1, *cond2;
	public:
		AndCondition(Condition *c1, Condition *c2){ cond1 = c1; cond2=c2;};
		bool test(){
			return cond1->test() && cond1->test();
		}
	};

	class WOLFORCE_API OrCondition: public Condition{
	private:
		Condition *cond1, *cond2;
	public:
		OrCondition(Condition *c1, Condition *c2){ cond1 = c1; cond2=c2;};
		bool test(){
			return cond1->test() || cond1->test();
		}
	};

	template<class Type>
	class WOLFORCE_API EqualCondition: public Condition{
	private:
		Type value1, value2;
	public:
		EqualCondition(Type v1, Type v2){ value1 = v1; value2=v1;};
		bool test(){
			return value1 == value2;
		}
	};

	template<class Type>
	class WOLFORCE_API LesserCondition: public Condition{
	private:
		Type *value1, *value2;
	public:
		LesserCondition(Type &v1, Type &v2){ value1 = v1; value2=v1;};
		bool test(){
			return *value1 < *value2;
		}
	};

	template<class T>
	class WOLFORCE_API CallbackCondition: public Condition{
	private:
		bool (T::*cbc)(void);
		T *who;
	public:
		CallbackCondition(T *w, bool (T::*func)(void)){ 
			cbc = func; who = w;
		}
		bool test(){
			return (who->*cbc)();
		}
	};

	template<class T>
	class WOLFORCE_API CallbackAction: public Action{
	private:
		void (T::*cbc)(void);
		T *who;
	public:
		CallbackAction(T *w, void (T::*func)(void)){ 
			cbc = func; who = w;
		}
		void exec(){
			(who->*cbc)();
		}
	};
}
#endif