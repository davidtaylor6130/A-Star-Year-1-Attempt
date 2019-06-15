#include "Level1.h"

Level1::Level1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	sprite1 = new Sprite("aStarWorking.png", renderer);
	location = new Rect2D(0, 0, 150, 150);
	spriteLocation = new Rect2D(200, 200, 150, 150);

	Vector2D temp(0, 0);

	for (int i = 0; i < heightOfTilePlaced; i++)
	{
		temp.y = i * widthHight;
		for (int j = 0; j < lengthOfTilePlaced; j++)
		{
			temp.x = j * widthHight;
			tilePlaced[i][j] = new tile(renderer, temp, true);
		}
	}

	tilePlaced[0][0]->startPoint = true;
	tilePlaced[1][1]->isItBlocked = true;
	tilePlaced[13][24]->endPoint = true;

}

Level1::~Level1()
{
}

void Level1::Render()
{
	for (int i = 0; i < heightOfTilePlaced; i++)
	{
		for (int j = 0; j < lengthOfTilePlaced; j++)
		{
			tilePlaced[i][j]->render();
		}
	}
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	for (int i = 0; i < heightOfTilePlaced; i++)
	{
		for (int j = 0; j < lengthOfTilePlaced; j++)
		{
			tilePlaced[i][j]->update();
		}
	}
}
