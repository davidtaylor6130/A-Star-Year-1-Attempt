#pragma once

#ifndef EVENTS_H
#define EVENTS_H

#include <SDL.h>
#include "structs.h"
namespace Events
{
	bool isKeyDown(SDL_Keycode key, SDL_Event& e);
	bool isKeyUp(SDL_Keycode key, SDL_Event& e);

	// -- David Was Here --- //

	bool isMouseLeftDown(SDL_Event& e);
	bool isMouseRightDown(SDL_Event& e); 

	Vector2D mousePosition();
}

#endif