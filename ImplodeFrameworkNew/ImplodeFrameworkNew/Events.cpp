#include "Events.h"

bool Events::isKeyDown(SDL_Keycode key, SDL_Event &e)
{
	if (SDL_KEYDOWN) //is a key pressed down?
	{
		if (e.key.keysym.sym == key) //is the key equal to the key inputted?
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Events::isKeyUp(SDL_Keycode key, SDL_Event& e)
{
	if (SDL_KEYUP) //check if a key is up
	{
		if (e.key.keysym.sym == key) //is the key equal to the key inputted
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}