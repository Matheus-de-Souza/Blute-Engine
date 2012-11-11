#ifndef LEVEL_H
#define LEVEL_H
#include "dllDefine.h"

namespace WolfEngine{
	
	class WOLFORCE_API Level
	{
	public:
		virtual void load(char *p) = 0;
	};
}

#endif