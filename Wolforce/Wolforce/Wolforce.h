// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WOLFORCE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WOLFORCE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef WOLFORCE_EXPORTS
#define WOLFORCE_API __declspec(dllexport)
#else
#define WOLFORCE_API __declspec(dllimport)
#endif

#ifdef __cplusplus    // If used by C++ code,
extern "C" {          // we need to export the C interface
#endif


	

// This class is exported from the Wolforce.dll
	//WOLFORCE_API int a;
	//class WOLFORCE_API AnimationEntry;
	//class WOLFORCE_API WolfEngine::Animation;
	//class WOLFORCE_API WolfEngine::Audio;

#ifdef __cplusplus
}
#endif 