#include "tile.h"

tile::tile(SDL_Renderer* renderer, Vector2D position, bool inputVisualShowing)
{

	mRenderer = renderer;
	visualShowing = inputVisualShowing;
	
	if (visualShowing)
	{
		mPosition = Rect2D(position.x, position.y, 50, 50);
		textureSelection = Rect2D(0, 0, 50, 50);
		sprite = new Sprite("aStarWorking.png", mRenderer);
		SDL_Color colour = { 250,250,250 };
		text = new Text("ttf/8-BIT_WONDER.ttf", 10, " ", colour, mRenderer, false, 25, 25, mPosition.x + 10, mPosition.y + 10);
	}
}

tile::~tile()
{
}

void tile::update()
{
	text->Update();

	if (startPoint == true)
	{
		textureSelection.x = 150;
	}
	else if (endPoint == true)
	{
		textureSelection.x = 100;
	}
	else if (isItBlocked == true)
	{
		textureSelection.x = 200;
	}
	else if (isItPath == true)
	{
		textureSelection.x = 50;
	}
	else
	{
		textureSelection.x = 0;
	}

}

void tile::render()
{
	if (visualShowing)
	{
		sprite->Render(textureSelection, mPosition, SDL_FLIP_NONE);
		text->Render();
	}
}
