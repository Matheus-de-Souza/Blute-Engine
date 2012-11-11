#include "LuaVirtualMachine.h"

#include "LuaGameObject.hpp"
#include "LuaInput.hpp"

#include "Diluculum\LuaWrappers.hpp"

LuaVirtualMachine::LuaVirtualMachine(){		
	DILUCULUM_REGISTER_CLASS(state["GameObject"], LuaGameObject);		
	DILUCULUM_REGISTER_CLASS(state["Input"], LuaInput);		

	setKeys();
}

int LuaVirtualMachine::getInt(string key){
	return static_cast<int>(state[key].value().asNumber());
}

std::string LuaVirtualMachine::getString(std::string key){
	return state[key].value().asString();
}

double LuaVirtualMachine::getDouble(std::string key){
	return state[key].value().asNumber();
}

bool LuaVirtualMachine::getBool(std::string key){
	return state[key].value().asBoolean();
}

void LuaVirtualMachine::set(std::string key,int value){
	state[key] = value;
}

void LuaVirtualMachine::set(std::string key,std::string value){
	state[key] = value;
}

void LuaVirtualMachine::set(std::string key,double value){
	state[key] = value;
}

void LuaVirtualMachine::set(std::string key,bool value){
	state[key] = value;
}

void LuaVirtualMachine::execString(std::string n){
	state.doString(n);
}

void LuaVirtualMachine::loadFile(std::string n){	
	state.doFile(n);
}

GameObject *LuaVirtualMachine::getGameObject(std::string nameGo){
	LuaGameObject *go = state[nameGo].value().asObjectPtr<LuaGameObject*>();
	return go->getGameObject();
}

void LuaVirtualMachine::setKeys(){	
state["KEY_SPACE"] = 0x20;
state["KEY_PRIOR"]= 0x21;
state["KEY_NEXT"] = 0x22;
state["KEY_END"]  = 0x23;
state["KEY_HOME"] = 0x24;
state["KEY_LEFT"] = 0x25;
state["KEY_UP"]   = 0x26;
state["KEY_RIGHT"]= 0x27;
state["KEY_DOWN"] = 0x28;
state["KEY_SELECT"] = 0x29;
state["KEY_PRINT"]= 0x2A;
state["KEY_EXECUT"] = 0x2B;
state["KEY_SNAPSHOT"] = 0x2C;
state["KEY_INSERT"] = 0x2D;
state["KEY_DELETE"]  = 0x2E;
state["KEY_HELP"] = 0x2F;
state["KEY_KEY_0"]= 0x30;
state["KEY_KEY_1"]= 0x31;
state["KEY_KEY_2"]= 0x32;
state["KEY_KEY_3"]= 0x33;
state["KEY_KEY_4"]= 0x34;
state["KEY_KEY_5"]= 0x35;
state["KEY_KEY_6"]= 0x36;
state["KEY_KEY_7"]= 0x37;
state["KEY_KEY_8"]= 0x38;
state["KEY_KEY_9"]= 0x39;
state["KEY_KEY_A"]= 0x41;
state["KEY_KEY_B"]= 0x42;
state["KEY_KEY_C"]= 0x43;
state["KEY_KEY_D"]= 0x44;
state["KEY_KEY_E"]= 0x45;
state["KEY_KEY_F"]= 0x46;
state["KEY_KEY_G"]= 0x47;
state["KEY_KEY_H"]= 0x48;
state["KEY_KEY_I"]= 0x49;
state["KEY_KEY_J"]= 0x4A;
state["KEY_KEY_K"]= 0x4B;
state["KEY_KEY_L"]= 0x4C;
state["KEY_KEY_M"]= 0x4D;
state["KEY_KEY_N"]= 0x4E;
state["KEY_KEY_O"]= 0x4F;
state["KEY_KEY_P"]= 0x50;
state["KEY_KEY_Q"]= 0x51;
state["KEY_KEY_R"]= 0x52;
state["KEY_KEY_S"]= 0x53;
state["KEY_KEY_T"]= 0x54;
state["KEY_KEY_U"]= 0x55;
state["KEY_KEY_V"]= 0x56;
state["KEY_KEY_W"]= 0x57;
state["KEY_KEY_X"]= 0x58;
state["KEY_KEY_Y"]= 0x59;
state["KEY_KEY_Z"]= 0x5A;
state["KEY_LWIN"] = 0x5B;
state["KEY_RWIN"] = 0x5C;
state["KEY_APPS"] = 0x5D;
state["KEY_SLEEP"]= 0x5F;
state["KEY_NUMPAD0"] = 0x60;
state["KEY_NUMPAD1"] = 0x61;
state["KEY_NUMPAD2"] = 0x62;
state["KEY_NUMPAD3"] = 0x63;
state["KEY_NUMPAD4"] = 0x64;
state["KEY_NUMPAD5"]= 0x65;
state["KEY_NUMPAD6"] = 0x66;
state["KEY_NUMPAD7"] = 0x67;
state["KEY_NUMPAD8"] = 0x68;
state["KEY_NUMPAD9"] = 0x69;
state["KEY_MULTIPLY"] = 0x6A;
state["KEY_ADD"] = 0x6B;
state["KEY_SEPARATOR"] = 0x6C;
state["KEY_SUBTRACT"] = 0x6D;
state["KEY_DECIMAL"] = 0x6E;
state["KEY_DIVIDE"] = 0x6F;
state["KEY_F1"] = 0x70;
state["KEY_F2"] = 0x71;
state["KEY_F3"] = 0x72;
state["KEY_F4"] = 0x73;
state["KEY_F5"] = 0x74;
state["KEY_F6"] = 0x75;
state["KEY_F7"] = 0x76;
state["KEY_F8"] = 0x77;
state["KEY_F9"] = 0x78;
state["KEY_F10"] = 0x79;
state["KEY_F11"] = 0x7A;
state["KEY_F12"] = 0x7B;
state["KEY_F13"] = 0x7C;
state["KEY_F14"] = 0x7D;
state["KEY_F15"] = 0x7E;
state["KEY_F16"] = 0x7F;
state["KEY_F17"] = 0x80;
state["KEY_F18"] = 0x81;
state["KEY_F19"] = 0x82;
state["KEY_F20"] = 0x83;
state["KEY_F21"] = 0x84;
state["KEY_F22"] = 0x85;
state["KEY_F23"] = 0x86;
state["KEY_F24"] = 0x87;
state["KEY_NUMLOCK"] = 0x90;
state["KEY_SCROLL"]= 0x91;
state["KEY_LSHIFT"]= 0xA0;
state["KEY_RSHIFT"]= 0xA1;
state["KEY_LCONTROL"]= 0xA2;
state["KEY_RCONTROL"] = 0xA3;
state["KEY_LMENU"]= 0xA4;
state["KEY_RMENU"]= 0xA5;
state["KEY_PLUS"] = 0xBB;
state["KEY_COMMA"]= 0xBC;
state["KEY_MINUS"]= 0xBD;
state["KEY_PERIOD"] = 0xBE;
}