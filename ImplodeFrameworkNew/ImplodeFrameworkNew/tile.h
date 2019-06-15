#pragma once
#include "structs.h"
#include "Sprite.h"
#include "Text.h"

class tile
{
public:

	bool visualShowing;
	bool startPoint;
	bool endPoint;
	bool isItBlocked;

	int pathFindingValue;

	Rect2D textureSelection;
	Rect2D mPosition;

	Sprite* sprite;
	Text* text;

	SDL_Renderer* mRenderer;

	tile(SDL_Renderer* renderer, Vector2D position, bool inputVisualShowing);
	~tile();

	void update();
	void render();

};

