#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "SDL.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Events.h"
#include "Collisions.h"
#include "Constants.h"
#include "music.h"

using namespace Events;
using namespace Collisions;

class GameScreen
{
protected:
	SDL_Renderer* mRenderer;
public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	//Inherited classes will call update and render functions, this is used to define how the gamescreen class will work
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
};

#endif