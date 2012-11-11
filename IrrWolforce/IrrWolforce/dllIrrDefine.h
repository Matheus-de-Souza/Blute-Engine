#ifdef IRRWOLFORCE_EXPORTS
#define IRRWOLFORCE_API __declspec(dllexport)
#else
#define IRRWOLFORCE_API __declspec(dllimport)
#endif