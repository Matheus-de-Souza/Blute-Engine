#ifndef GUI_ENVIRONMENT_H
#define GUI_ENVIRONMENT_H
#include "dllDefine.h"
#include <string>
//#include "Behavior.h"


namespace WolfEngine{

	class WOLFORCE_API GUIEnvironment
	{
	public:


		virtual void loadImage(std::string name, char *p){};
		virtual void addImage(std::string texName, std::string imgName, int, int){} ;	

		virtual void makeVisible(std::string name) {};
		virtual void makeInvisible(std::string name){};

		virtual void update() = 0;
	};
}

#endif

