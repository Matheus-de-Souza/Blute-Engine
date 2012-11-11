#ifndef LUA_GO_H
#define LUA_GO_H

#include "GameObject.h"
#include "Diluculum\Types.hpp"
#include "Diluculum\LuaExceptions.hpp"
#include "Diluculum\LuaWrappers.hpp"

using namespace WolfEngine;

class LuaGameObject{
public:
	LuaGameObject(const Diluculum::LuaValueList& params){
		go = new GameObject;
	}

	Diluculum::LuaValueList setName(const Diluculum::LuaValueList& params){
         if (params.size() != 1) throw Diluculum::LuaError ("Exactly one parameter was expected.");         
		 go->setName(new std::string(params[0].asString()));
		 return LuaValueList();
	}

	GameObject *getGameObject(){
		return go;
	}
private:
	GameObject *go;
};

DILUCULUM_BEGIN_CLASS(LuaGameObject);
  DILUCULUM_CLASS_METHOD(LuaGameObject, setName);
DILUCULUM_END_CLASS(LuaGameObject);

#endif