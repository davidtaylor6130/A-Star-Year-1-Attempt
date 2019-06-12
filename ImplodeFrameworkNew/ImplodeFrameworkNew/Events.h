#pragma once

#ifndef EVENTS_H
#define EVENTS_H

#include <SDL.h>
namespace Events
{
	bool isKeyDown(SDL_Keycode key, SDL_Event& e);
	bool isKeyUp(SDL_Keycode key, SDL_Event& e);
}

#endif