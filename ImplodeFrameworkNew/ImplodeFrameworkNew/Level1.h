#pragma once

#define coloms 25
#define rows 14


#define startPosition Vector2D(10,10)
#define endPosition Vector2D(2,2)


#include "GameScreen.h"
#include "Events.h"
#include "tile.h"

using namespace Events;

class Level1 : public GameScreen
{
public:
	int xPos;
	int yPos;
	
	bool KeyDown = false;
	Vector2D startNode;
	Vector2D currentNode;
	Vector2D endPos;

	int widthHight = 50;
	int lengthOfTilePlaced = coloms;
	int heightOfTilePlaced = rows;

	tile* tilePlaced[rows][coloms];

	Rect2D* location;
	Rect2D* spriteLocation;

	Level1(SDL_Renderer* renderer);
	~Level1();
	void Render();
	void Update(float deltaTime, SDL_Event e);
	void createRoute();
private:
};
