/*
    WolfForce Engine Project - 3D Game Engine Project
	IrrWolforce - Irrlicht eXtension for WolfForce Engine Project
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

#include "IrrInput.h"

using namespace IrrWolforce;

IrrInput::IrrInput()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
	mouseWheel = 0;

}

bool IrrInput::OnEvent(const SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT){
		//Marca da tecla (obtida no evento) como pressionada
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	}
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {	
		 switch(event.MouseInput.Event) 
		 {
            case EMIE_LMOUSE_PRESSED_DOWN:
                    KeyIsDown[KEY_LBUTTON] = true;
                    break;

            case EMIE_LMOUSE_LEFT_UP:
                    KeyIsDown[KEY_LBUTTON] = false;
                    break;
			case EMIE_RMOUSE_PRESSED_DOWN:
				KeyIsDown[KEY_RBUTTON] = true;
                    break;

			case EMIE_RMOUSE_LEFT_UP:
                    KeyIsDown[KEY_RBUTTON] = false;
                    break;

			case EMIE_MOUSE_WHEEL:
				mouseWheel = event.MouseInput.Wheel;
				break;			

			default : break;
		 }
	}
	return false;
}

bool IrrInput::isKeyDown(int keyCode)
{
	return KeyIsDown[keyCode];
}


void IrrInput::clear()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}

float IrrInput::getMouseWheel()
{
	float temp = mouseWheel;
	mouseWheel = 0;
	return temp;
}
