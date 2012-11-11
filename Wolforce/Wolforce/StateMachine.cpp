#include "StateMachine.h"

using namespace WolfEngine;

bool Transition::isTriggered()
{
	return this->condition->test();
}

State::State()
{
	outgoing = new list<Transition*>();
	actions = new list<Action*>();
	this->entryAction = NULL;
	this->exitAction = NULL;
}

void State::addTransition(Transition *t)
{
	outgoing->push_back(t);
}

void State::addAction(Action *a)
{
	actions->push_back(a);
}

StateMachine::StateMachine(State *s)
{
	this->initialState = s;
	this->currentState = this->initialState;
	this->states = new list<State*>();
	addState(s);
}

list<Action*> *StateMachine::update(list<Action*> *actions)
{
	Transition *triggeredTransition = NULL;
	State *targetState =NULL;
	list<Transition*>::const_iterator i = currentState->getTransitions()->begin();
	while(i!=currentState->getTransitions()->end()){
		if((*i)->isTriggered()){
			triggeredTransition = *i;
			break;
		}
		i++;
	}
	if(triggeredTransition!=NULL){
		targetState = triggeredTransition->getTargetState();
		if(currentState->getExitAction())
			actions->push_back(currentState->getExitAction());
		if(triggeredTransition->getAction())
			actions->push_back(triggeredTransition->getAction());
		if(targetState->getEntryAction())
			actions->push_back(targetState->getEntryAction());
		currentState = targetState;
		return actions;
	}
	else{
		return currentState->getAction();
	}
}

void StateMachine::addState(State *s)
{
	states->push_back(s);
}