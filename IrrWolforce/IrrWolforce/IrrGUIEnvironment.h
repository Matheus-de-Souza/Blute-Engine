#ifndef IRR_GUI_ENVIRONMENT_H
#define IRR_GUI_ENVIRONMENT_H

#include "irrlicht.h"

#include "GUIEnvironment.h"

#include <string>
#include <map>

using namespace WolfEngine;
using namespace std;

using namespace irr;
using namespace gui;
using namespace video;
#include "dllIrrDefine.h"
namespace IrrWolforce
{
	class IRRWOLFORCE_API IrrGUIEnvironment : public GUIEnvironment
	{
	public:
		IrrGUIEnvironment(void);
		IrrGUIEnvironment(IGUIEnvironment *ge);
		IrrGUIEnvironment(IGUIEnvironment *ge, IVideoDriver *vd);

		void loadImage(std::string name, char *p);
		void addImage(std::string texName, std::string imgName, int, int);

		void makeVisible(std::string n);
		void makeInvisible(std:: string n);

		void update();		

		~IrrGUIEnvironment(void);

	private:
		IGUIEnvironment *guiEnv;
		IVideoDriver *driver;	

	protected:
		std::map<std::string, ITexture *> *guiTextures;
		std::map<std::string, IGUIImage *> *guiImages;
	};
}

#endif