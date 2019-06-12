/* CC BY Creative Commons license
Distribution and publication of Framework allowed
Implode Games owns all credit for base game engine technology in this framework
Not mandatory but credit to ImplodeGames in distributed/published material is highly appreciated
*/

/* IMPLODE FRAMEWORK
A framework for SDL using optimised functionality of Game logic
To be used for creating small 2D games as a layer underneath a true Game Engine
--------------------------------------------------------------------------------
Authors:
-David "Basically" Taylor
-Joe "Derby Ginger" Pickering
-Anthony "Wolvo Ginger" Sturdy
-Liam "Verdict" McMullen
*/
//------------------------------------------------------------------------------

#include <iostream>
#include "ImpFramework.h"
#include "Level1.h"
using namespace std;
using namespace ImplodeFramework;

class Level1;

Level1* FirstLevel;

//This is the source file for the SDL project
//all DLL's and Libs are located using $(PROJECTDIR)\
//when adding more SDL Files, use this notation

int main(int argc, char* args[])
{
	//Initialise SDL Pass in a game title, the dimensions, frequency for music, channels and finally chunksize
	bool quit = !InitSDL("GameTitle", 1280, 720, 44100, 2, 2048);

	FirstLevel = new Level1(gRenderer);
	ScreenManager->ChangeScreen(FirstLevel);
	while (!quit)
	{
		Render();
		quit = Update();
	}
	CloseSdl();
	return 0;
}