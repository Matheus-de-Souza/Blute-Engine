#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>

#include "Mundo.h"

int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
	
	ShowCursor(FALSE);

	Mundo::MenuPrincipal();

	return 0;
}