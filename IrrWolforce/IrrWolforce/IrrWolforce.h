// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IRRWOLFORCE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IRRWOLFORCE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef IRRWOLFORCE_EXPORTS
#define IRRWOLFORCE_API __declspec(dllexport)
#else
#define IRRWOLFORCE_API __declspec(dllimport)
#endif

#ifdef __cplusplus    // If used by C++ code,
extern "C" {          // we need to export the C interface
#endif

#ifdef __cplusplus
}
#endif 