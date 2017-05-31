#include "Game.h"
#include<windows.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
             LPSTR lpCmdLine, int nCmdShow )
{
	sGame->Init();
	sGame->Run();

    return 0 ;
}