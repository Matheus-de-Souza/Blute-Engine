#ifndef LUA_INPUT_H
#define LUA_INPUT_H

#include "Input.h"
#include "Diluculum\Types.hpp"
#include "Diluculum\LuaExceptions.hpp"
#include "Diluculum\LuaWrappers.hpp"
#include "Diluculum\LuaValue.hpp"

using namespace WolfEngine;

class LuaInput{
public:
	LuaInput(const Diluculum::LuaValueList& params){
	}

	Diluculum::LuaValueList registry(const Diluculum::LuaValueList& params){
         if (params.size() != 2) throw Diluculum::LuaError ("Exactly one parameter was expected.");         
		 Input::registry((char*)params[0].asString().c_str(),params[1].asInteger());  
		 return LuaValueList();
	}
};

DILUCULUM_BEGIN_CLASS(LuaInput);
  DILUCULUM_CLASS_METHOD(LuaInput, registry);
DILUCULUM_END_CLASS(LuaInput);

#endif