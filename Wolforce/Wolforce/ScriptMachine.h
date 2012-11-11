#ifndef SCRIPT_MACHINE_H
#define SCRIPT_MACHINE_H

#include <string>
#include "GameObject.h"

using namespace std;
using namespace WolfEngine;

class ScriptMachine{

public:
	virtual int getInt(std::string) = 0;
	virtual std::string getString(std::string) = 0;
	virtual double getDouble(std::string) = 0;
	virtual bool getBool(std::string) = 0;

	virtual void set(std::string,int) = 0;
	virtual void set(std::string,std::string) = 0;
	virtual void set(std::string,double) = 0;
	virtual void set(std::string,bool) = 0;

	virtual void execString(std::string) = 0;
	virtual void loadFile(std::string) = 0;

	virtual GameObject *getGameObject(std::string) = 0;
};
#endif