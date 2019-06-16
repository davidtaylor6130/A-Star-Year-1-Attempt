#include "Events.h"

bool Events::isKeyDown(SDL_Keycode key, SDL_Event &e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN: //is a key pressed down?
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
	}
	return false;
}

bool Events::isKeyUp(SDL_Keycode key, SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_KEYUP: //is a key pressed down?
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
	}
	return false;
	
}

bool Events::isMouseLeftDown(SDL_Event& e)
{

	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			return true;
			break;
		}
		break;
	}

	return false;
}

bool Events::isMouseRightDown(SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.button)
		{
		case SDL_BUTTON_RIGHT:
			return true;
			break;
		}
		break;
	}

	return false;
}

Vector2D Events::mousePosition()
{
	Vector2D mousePosition;
	SDL_GetMouseState(&mousePosition.x,&mousePosition.y);
	return mousePosition;
}
