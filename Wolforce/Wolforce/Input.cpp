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
#include "Input.h"
#include <iostream>

using namespace WolfEngine;
using namespace std;

InputReceiver *Input::receiver = NULL;
multimap<string,int> *Input::keys = new multimap<string,int>();

void Input::setReceiver(InputReceiver *r)
{
	receiver = r;
}

bool Input::getButton(char *c)
{
	string t(c);
	multimap<string, int>::iterator i =	keys->find(t);
	if(i==keys->end()){
		return false;
	}
	else{
		multimap<string, int>::iterator lastElement = keys->upper_bound(t);
		for(; i != lastElement; ++i){
			if(receiver->isKey(i->second)){
				return true;
			}
		}	
	}
	return false;
}

bool Input::getButtonDown(char *c)
{
	string t(c);
	multimap<string, int>::iterator i =	keys->find(t);
	if(i==keys->end()){
		return false;
	}
	else{
		multimap<string, int>::iterator lastElement = keys->upper_bound(t);
		for(; i != lastElement; ++i){
			if(receiver->isKeyDown(i->second)){
				return true;
			}
		}	
	}
	return false;
}

bool Input::getButtonUp(char *c)
{
	string t(c);
	multimap<string, int>::iterator i =	keys->find(t);
	if(i==keys->end()){
		return false;
	}
	else{
		multimap<string, int>::iterator lastElement = keys->upper_bound(t);
		for(; i != lastElement; ++i){
			if(receiver->isKeyUp(i->second)){
				return true;
			}
		}	
	}
	return false;
}

void Input::registry(char *t, int k)
{
	keys->insert(std::pair<string,int>(string(t),k));
}

void Input::clear()
{
	keys->clear();
}

float Input::getMouseWheel()
{
	return receiver->getMouseWheel();
}

int Input::GetMouseX()
{
	return receiver->GetMouseX();
}

int Input::GetMouseY()
{
	return receiver->GetMouseY();
}

int Input::GetMouseClick()
{
	return receiver->GetMouseClick();
}