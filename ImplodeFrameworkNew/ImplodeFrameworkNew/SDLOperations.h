#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include "GameScreenManager.h"
#include "GameScreen.h"

using namespace std;

class GameScreenManager;
class GameScreen;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Uint32 gOldTime;

GameScreenManager *ScreenManager = NULL;
GameScreen* tempScreen = NULL;

namespace SDLOperations
{
	//Since these values change the most, have the user input their own desired values
	bool InitSDL(const char* gameTitle, int screenWidth = 1280, int screenHeight = 720, int frequency = 44100, int channels = 2, int chunkSize = 2048);
	void Render();
	void CloseSdl();
	bool Update();
}

#include "SDLOperations.cpp"