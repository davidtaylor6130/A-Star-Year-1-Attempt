#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "SDL.h"
#include "Constants.h"
#include "GameScreen.h"
class GameScreenManager
{
private:
	SDL_Renderer* mRenderer;

public:
	GameScreenManager(SDL_Renderer* renderer, GameScreen * screen); 
	~GameScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(GameScreen * newScreen);

	GameScreen* mCurrentScreen;
	
};


#endif