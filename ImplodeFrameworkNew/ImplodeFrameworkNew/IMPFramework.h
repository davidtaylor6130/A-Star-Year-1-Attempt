#ifndef  SDL_INIT_NMSP_H
#define SDL_INIT_NMSP_H
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

#include "SDLOperations.h"
#include "Collisions.h"
#include "Sprite.h"
#include "GameScreenManager.h"
#include "Constants.h"
#include "GameScreen.h"
#include "Animation.h"
#include "Text.h"
#include "Sprite.h"
#include "music.h"

//this namespace will encapsulate all other namespaces that the framework will use
namespace ImplodeFramework
{
	using namespace SDLOperations; //Operations for SDL such as initialisation and closing
	using namespace Collisions;
}
#endif // ! SDL_INIT_NMSP_H
