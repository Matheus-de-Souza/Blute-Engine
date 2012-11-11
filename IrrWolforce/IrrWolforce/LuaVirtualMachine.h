#ifndef LUA_VM_H
#define LUA_VM_H

#include <string>

#include "Diluculum\LuaState.hpp"

#include "GameObject.h"
#include "ScriptMachine.h"

using namespace std;
using namespace Diluculum;

using namespace WolfEngine;

class LuaVirtualMachine: public ScriptMachine{
private:
	LuaState state;

	void setKeys();
public:
	LuaVirtualMachine(void);

	int getInt(std::string);
	std::string getString(std::string);
	double getDouble(std::string);
	bool getBool(std::string);

	void set(std::string,int);
	void set(std::string,std::string);
	void set(std::string,double);
	void set(std::string,bool);

	void execString(std::string);
	void loadFile(std::string);

	GameObject *getGameObject(std::string);
};
#endif