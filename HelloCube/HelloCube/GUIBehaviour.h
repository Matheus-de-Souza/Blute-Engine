#ifndef GUI_BEHAVIOUR
#define GUI_BEHAVIOUR

#include "Mundo.h"

class Mundo;
class GuiBehaviour : public Behavior
{
public:
	bool isInCredits;
	
	GUIEnvironment * gui;

	GuiBehaviour(GUIEnvironment * gui)
	{
		this->gui = gui;
		isInCredits = false;
	}

	void update()
	{
		if(Input::getButton("Escape"))
		{
			//gui = Engine::GetInstance()->getGUIEnvironment();
			Engine::GetInstance()->closeApplication();
		}
		else if (Input::getButtonDown("Credits"))
		{
			if(isInCredits)
			{
				gui->makeInvisible("credits");
				gui->makeVisible("main");
			}
			else 
			{
				gui->makeVisible("credits");
				gui->makeInvisible("main");
			}

			isInCredits = !isInCredits ;
		}
		else if(Input::getButtonDown("Credits"))
		{
			gui->makeInvisible("credits");
			gui->makeInvisible("main");
			//Mundo::Iniciar();
		}
	}
};
#endif