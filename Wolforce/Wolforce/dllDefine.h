
#ifdef WOLFORCE_EXPORTS
#define WOLFORCE_API __declspec(dllexport)
#else
#define WOLFORCE_API __declspec(dllimport)
#endif