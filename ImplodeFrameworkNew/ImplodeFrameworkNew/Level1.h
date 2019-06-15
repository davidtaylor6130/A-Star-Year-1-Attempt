#pragma once
#include "GameScreen.h"
#include "tile.h"

class Level1 : public GameScreen
{
public:
	int xPos;
	int yPos;
	Sprite* sprite;
	Sprite* sprite1;
	Animation* anim;
	Text * text;
	tile* tile1;
	tile* tile2;

	int widthHight = 50;
	int lengthOfTilePlaced = 25;
	int heightOfTilePlaced = 14;

	tile* tilePlaced[14][25];

	Rect2D* location;
	Rect2D* spriteLocation;

	Level1(SDL_Renderer* renderer);
	~Level1();
	void Render();
	void Update(float deltaTime, SDL_Event e);
private:
};
